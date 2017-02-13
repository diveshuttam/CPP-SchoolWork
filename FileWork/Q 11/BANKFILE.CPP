#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<process.h>

int inital_acno=1000;

struct date
{
int dd;
int mm;
int yy;
};

class master
{
 int acno;
 char nm[20];
 float bal;
 public:
 master()
 {
 acno=inital_acno-1;
 strcpy(nm,"null");
 bal=0;
 }

 ~master()
 {
 cout<<"";
 }

 void enter(int tacno)
 {
 cout<<"\nEnter Name\t\t";
 gets(nm);
 cout<<"Enter Initial Balance\t";
 cin>>bal;
 acno=tacno;
 cout<<"Account no. assigned\t"<<acno;
 }

 void display()
 {
 cout<<"\nAccount No.\t"<<acno;
 cout<<"\nName\t\t"<<nm;
 cout<<"\nCurrent Balance\t"<<bal;
 }

 int withdraw(float w_amt)
 {
 if(bal-w_amt>=1000)
  {
  bal-=w_amt;
  cout<<"\n\nWithdrawal Successful\nCurrent A/C status is\n";
  display();
  return 1;
  }
 else
  {
   cout<<"\nWithdrawal Could Not Be completed due to Insufficient Balance\n";
   display();
   return 0;
  }
 }

 int deposit(float d_amt)
 {
  bal+=d_amt;
  cout<<"\nDeposit Sucessful\nCurrent A/C status is\n";
  display();
  return 1;
 }

 void displayt()     	//for tabular form in func. dispall()
 {
 cout<<acno<<"\t"<<nm<<"\t\t"<<bal;
 }

 int retacno()
 {
 return acno;
 }
};

class transaction
{
 int tacno;
 date tdate;
 char ttype;
 float tamt;
 public:
 transaction()
 {
 tacno=0;
 tdate.dd=1;
 tdate.mm=1;
 tdate.yy=2000;
 ttype='n';
 tamt=0.0;
 }

 ~transaction()
 {
 cout<<"";
 }
 void create(int acno,date d,char type,float amt)
 {
 tacno=acno;
 tdate=d;
 ttype=type;
 tamt=amt;
 }

 void display()
 {
 cout<<"\n"<<tacno<<"\t"<<tdate.dd<<"/"<<tdate.mm<<"/"<<tdate.yy
     <<"\t"<<ttype
     <<"\t"<<tamt;
 }

 int retacno()
 {
 return tacno;
 }
};

////////////////////////////////////////////////////////////////////////////
void newac();
void delac();
void withdraw();
void deposit();
void dispreq();
void dispall();
void dispreqtrans(int tacno);
void disp_acwise_trans();
////////////////////////////////////////////////////////////////////////////

void main()
{
int choice;

do
 {
  clrscr();
  cout<<"\nMain Menu\n"
      <<"\nl)\tNew Account"
      <<"\n2)\tDelete Account"
      <<"\n3)\tWithdraw Money"
      <<"\n4)\tDeposit Money"
      <<"\n5)\tDisplay Required"
      <<"\n6)\tDisplay All"
      <<"\n7)\tDisplay Account-Wise Transaction Details"
      <<"\n8)\tExit"
      <<"\n\nEnter Your Choice (1-8)\t"; cin>>choice;

  switch(choice)
  {
   case 1:
	newac();
	break;
   case 2:
	delac();
	break;
   case 3:
	withdraw();
	break;
   case 4:
	deposit();
	break;
   case 5:
	dispreq();
	break;
   case 6:
	dispall();
	break;
   case 7:
	disp_acwise_trans();
	break;
   case 8:
	exit(0);
	break;
  default:cout<<"Invalid Choice:";
  }
  cout<<"\n\nPress Y to Continue\n";
 }while(toupper(getche())=='Y');
}
/**************************************************************************/
///////////////////////////////////////////////////////////////////////////
void newac()
{
cout<<"\n\nPress Any Key To Clear Screen";
getche();
clrscr();

cout<<"\nWelcome To New Acccout Creation\n";
int acno;
master m;
ifstream fin;

fin.open("master.dat",ios::binary);
if(!fin)
  acno=inital_acno;
else
   {
   fin.seekg(-(int)sizeof(m),ios::end);
   fin.read((char*)&m,sizeof(m));
   acno=m.retacno()+1;
   }
fin.close();

//now m used to get last account no is of no use hence it is again used to
//enter ac details
m.enter(acno);
//opening master.dat in out (append) mode
ofstream fout;
fout.open("master.dat",ios::binary|ios::app);
if(!fout)
	cout<<"Error In Opening File /'Master/'";
else
	{
	fout.write((char*)&m,sizeof(m));
	}
}
///////////////////////////////////////////////////////////////////////////
void delac()
{
cout<<"\n\nPress Any Key To Clear Screen";
getche();
clrscr();

master m;
int tacno;
ifstream fin;
ofstream tfout;
int flag=0;

cout<<"Enter The Account No. That You Want to Delete";	cin>>tacno;

fin.open("master.dat",ios::binary);
tfout.open("temp.dat",ios::binary);

if(!fin||!tfout)
  cout<<"Error, The file(s) Couldn't be Opened";
else
   {
   fin.seekg(0);
    while(fin.read((char*)&m,sizeof(m)))
      {
      if(m.retacno()!=tacno)
      tfout.write((char*)&m,sizeof(m));
      else
      flag=1;	//to check if rec was found
      }
    if(flag==1)
       {
	//closing master and temp
	fin.close();
	tfout.close();
	remove("master.dat");
	rename("temp.dat","master.dat");
	cout<<"\nGiven A/C deleted from \'master.dat\'";

	//deleting transactions
	cout<<"\nDeleting Transactions(if any)";
	cout<<"\nPress Any Key";
	getch();
	cout<<"\n\n";

	fin.open("trans.dat",ios::binary);
	tfout.open("temp.dat",ios::binary);
	if(!fin||!tfout)
	cout<<"\nThe File Transactions or Temp Couldn't Be Opened";
	else
	  {
	  transaction t;
	  fin.seekg(0);
	  while(fin.read((char*)&t,sizeof(t)))
	     {
	     if(t.retacno()!=tacno)
	     tfout.write((char*)&t,sizeof(t));
	     }

	  fin.close();
	  tfout.close();

	  remove("trans.dat");
	  rename("temp.dat","trans.dat");
	  cout<<"\n Transactions Deleted";
	  }
      }
   else
      {
      cout<<"\n A/C not found";
      fin.close();
      tfout.close();
      remove("temp.dat");
      }
  }
}
///////////////////////////////////////////////////////////////////////////
void withdraw()
{
cout<<"\n\nPress Any Key To Clear Screen";
getche();
clrscr();

int tacno;
int flag_found=0;
int flag_success=0;
float tamt;
fstream finout;
master m;

finout.open("master.dat",ios::binary|ios::out|ios::ate|ios::in|ios::nocreate);

cout<<"\nEnter A/C no.\t";	cin>>tacno;

if(!finout)
       cout<<"error, file \'master.dat\' couldn't be opened";
else
       {
       finout.seekg(0);
       while(finout.read((char*)&m,sizeof(m)))
		{
		if(m.retacno()==tacno)
		  {
		  flag_found=1;
		  break;
		  }
		}
       if(flag_found==1)
	 {
	 cout<<"Enter Amount You Want to Withdraw";	cin>>tamt;
	 flag_success=m.withdraw(tamt);
	 finout.seekg(-(int)sizeof(m),ios::cur);
	 finout.write((char*)&m,sizeof(m));
	 }
       else
	 cout<<"Account not found";

       finout.close();

       //writing the transaction in file trans.dat
       if(flag_success==1)
		{
		ofstream fout;
		fout.open("trans.dat",ios::binary|ios::app);

		if(!fout)
		  cout<<"Error File \'transaction.dat\' could not be opened";
		else
		  {
		  transaction t;
		  date d;
		  cout<<"\nEnter Date Of Transaction\n";
		  cout<<"\nDate(dd)";	cin>>d.dd;
		  cout<<"\nMonth(mm)";  cin>>d.mm;
		  cout<<"\nYear(yy)";   cin>>d.yy;
		  t.create(tacno,d,'w',tamt);
		  fout.write((char*)&t,sizeof(t));
		  fout.close();
		  }
		}
       }
}
///////////////////////////////////////////////////////////////////////////
void deposit()
{
cout<<"\n\nPress Any Key To Clear Screen";
getche();
clrscr();

int tacno;
int flag_found=0;
int flag_success=0;
float tamt;
fstream finout;
master m;

finout.open("master.dat",ios::binary|ios::out|ios::ate|ios::in|ios::nocreate);

cout<<"\nEnter A/C no.\t";	cin>>tacno;

if(!finout)
       cout<<"error, file \'master.dat\' couldn't be opened";
else
       {
       finout.seekg(0);
       while(finout.read((char*)&m,sizeof(m)))
		{
		if(m.retacno()==tacno)
		  {
		  flag_found=1;
		  break;
		  }
		}
       if(flag_found==1)
	 {
	 cout<<"Enter Amount You Want to Deposit";	cin>>tamt;
	 flag_success=m.deposit(tamt);

	 finout.seekg(-(int)sizeof(m),ios::cur);
	 finout.write((char*)&m,sizeof(m));
	 }
       else
	 cout<<"Account not found";

       finout.close();

       //writing the transaction in file trans.dat
       if(flag_success==1)
		{
		ofstream fout;
		fout.open("trans.dat",ios::binary|ios::app);

		if(!fout)
		  cout<<"Error File \'transaction.dat\' could not be opened";
		else
		  {
		  transaction t;
		  date d;
		  cout<<"\nEnter Date Of Transaction\n";
		  cout<<"\nDate(dd)";	cin>>d.dd;
		  cout<<"\nMonth(mm)";  cin>>d.mm;
		  cout<<"\nYear(yy)";   cin>>d.yy;
		  t.create(tacno,d,'d',tamt);
		  fout.write((char*)&t,sizeof(t));
		  fout.close();
		  }
		}
       }

}
///////////////////////////////////////////////////////////////////////////
void dispreq()
{
cout<<"\n\nPress Any Key To Clear Screen";
getche();
clrscr();

master m;
int tacno;
ifstream fin;
int flag=0;

cout<<"Enter The Account No. That You Want to Display";	cin>>tacno;

fin.open("master.dat",ios::binary);

if(!fin)
  cout<<"Error, The file Couldn't be Opened";
else
   {
   fin.seekg(0);
    while(fin.read((char*)&m,sizeof(m)))
      {
      if(m.retacno()==tacno)
	  {
	  m.display();
	  flag=1;	  //to check if rec was found
	  cout<<"\n\nDo You Want To Display Transactions Also(Y/N)";
	  if(toupper(getche())=='Y')
	  dispreqtrans(tacno);
	  break;
	  }
      }
    if(flag==0)
       {
       cout<<"Not found";
       }
    fin.close();
    }
}
///////////////////////////////////////////////////////////////////////////
void dispall()
{
cout<<"\n\nPress Any Key To Clear Screen";
getche();
clrscr();
master m;
ifstream fin;

fin.open("master.dat",ios::binary);

if(!fin)
  cout<<"Error, The file Couldn't be Opened";
else
   {
   cout<<"\nA/C No\tName\t\tBal\n\n";
   fin.seekg(0);
    while(fin.read((char*)&m,sizeof(m)))
      {
	  m.displayt();
	  cout<<"\n";
      }
    fin.close();
   }
}
///////////////////////////////////////////////////////////////////////////
void dispreqtrans(int tacno)
{
transaction t;
ifstream fin;
int flag_found=0;


fin.open("trans.dat",ios::binary);

if(!fin)
  cout<<"\nError, The file Couldn't be Opened";
else
   {
   fin.seekg(0);
    while(fin.read((char*)&t,sizeof(t)))
      {
      if(t.retacno()==tacno)
	  {
	  if(flag_found==0)	//only for first time
	  {
	  cout<<"\n\nacno\tdate\t\ttype\tamount\n";
	  }

	  t.display();
	  flag_found=1;	  //if rec was found
	  }
      }
    if(flag_found==0)
       {
       cout<<"\nNo transactions found";
       fin.close();
       }
    }
}

void disp_acwise_trans()
{
cout<<"\n\nPress Any Key To Clear Screen";
getche();
clrscr();

master m;
ifstream fin;

fin.open("master.dat",ios::binary);

if(!fin)
  cout<<"Error, The file Couldn't be Opened";
else
   {
   fin.seekg(0);
    while(fin.read((char*)&m,sizeof(m)))
      {
	  cout<<"\n\nTransaction Details of A/C no.\t"<<m.retacno();
	  dispreqtrans(m.retacno());
      }
    fin.close();
   }
}
///////////////////////////////////////////////////////////////////////////