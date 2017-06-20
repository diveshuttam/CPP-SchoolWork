#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>

int penalty=100;
float minbal=1000;
int initacno=1000;

class account
{
 protected:
   char nm[20];
   int  acno;
   float bal;
   int cheque;
 public:
  void enter()
  {
  cout<<"\nEnter name";	cin>>nm;
  cout<<"\nEnter initial balance";	cin>>bal;
  acno=initacno++;
  }
  void display()
  {
  cout<<"\nAccount No\t\t"<<acno;
  cout<<"\nName\t\t\t"<<nm;
  cout<<"\nBalance\t"<<bal;
  cout<<"\nChequebook facility\t"<<cheque;
  }
};

class current:public account
{
 public:
 void enter()
 {
 account::enter();
 cheque=1;
 }
 void display()
 {
 account::display();
 }
 void deposit(int amt)
 {
 bal+=amt;
 cout<<"Done";
 display();
 }

 void withdraw(int amt)
 {
 if(bal-amt>=0)
  {
  bal-=amt;
  cout<<"Done";
  }
 else
  {
  cout<<"Unable To Withdraw Due to In sufficient balance";
  }
  display();
 }

 void check()
 {
 if(bal<minbal)
  {
  cout<<"Penalty Inposed";
  bal-=penalty;
  }
 else
  {
  cout<<"Penalty Not Imposed";
  }
 }

};

class saving:public account
{
 public:
 void enter()
 {
 account::enter();
 cheque=0;
 }

 void display()
 {
 account::display();
 }

 void deposit(int amt)
 {
 bal+=amt;
 cout<<"Done";
 display();
 }

 void withdraw(int amt)
 {
 if(bal-amt>=0)
  {
  bal-=amt;
  cout<<"Done";
  }
 else
  {
  cout<<"Unable To Withdraw Due to In sufficient balance";
  }
  display();
 }

 void interest()
 {
  float i;
  i=(float)bal*0.1*1;	//interest for 1 year
  bal+=i;
  display();
 }

};

void main()
{
//program shortened using only 2 objects
 clrscr();

 current c;
 saving  s;

 int choice;

 cout<<"\nEnter Info For Current Account\n";
 c.enter();
 cout<<"\nEnter Info For Savings Account\n";
 s.enter();

 int amt;

 cout<<"\nPress Any key To Clear Screen\t";
 getch();

 do
 {
 clrscr();
 cout	<<"main menu"
	<<"\n1)\tDisplay Both Accounts"
	<<"\n2)\tDeposit(Current)"
	<<"\n3)\tDeposit(savings)"
	<<"\n4)\tWithdraw(current)"
	<<"\n5)\tWithdraw(savings)"
	<<"\n6)\tCompute Interest(Savings Only)"
	<<"\n7)\tCheck Min balance(Current only)"
	<<"\n8)\tExit";
 cout<<"\nEnter Choice\t";     cin>>choice;

 switch(choice)
  {
  case 1:
	cout<<"\nSavings\n";
	s.display();
	cout<<"\nCurrent\n";
	c.display();
	break;
  case 2:
	cout<<"\nEnter Amt\t";	cin>>amt;
	c.deposit(amt);
	break;
  case 3:
	cout<<"\nEnter Amt\t";	cin>>amt;
	s.deposit(amt);
	break;
  case 4:
	cout<<"\nEnter Amt\t";	cin>>amt;
	c.withdraw(amt);
	break;
  case 5:
	cout<<"\nEnter Amt\t";	cin>>amt;
	s.withdraw(amt);
	break;
  case 6:
	s.interest();
	break;
  case 7:
	c.check();
	break;
  case 8:
	exit(0);
  }
 cout<<"\nPress Y To Continue";
 }while(toupper(getche())=='Y');
}