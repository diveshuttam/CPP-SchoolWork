#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>

int n=0,an=1000;
class bank
{
 int	acno;
 char	acnm[20];
 int	bal;
 char	type;

public:
 void	enter();
 void	display();
 void	withdraw(int amt);
 void	deposit(int amt);
 int	ret_acno();
};
 void	bank::enter()
 {
     acno=an++;
     cout<<"\nA/C Name\t"; cin>>acnm;
     cout<<"A/C Bal\t\t";  cin>>bal;
     cout<<"A/C Type\t"; cin>>type;
     cout<<"\nEntry Updated. "<<"The A/C No Alloted Is "<<acno;
 }
 void	bank::display()
 {
     cout<<"\nA/C No\t\t:"<<acno;
     cout<<"\nA/C Name\t:"<<acnm;
     cout<<"\nBalance\t\t:"<<bal;
     cout<<"\nType\t\t:"<<type;
 }
 void	bank::withdraw(int amt)
 {
     if(bal-amt>1000)
     {
	bal-=amt;
	cout<<"Withdrawal Successful!\n New A/C Balance is\t"<<bal<<"\n";
     }
     else
     {
	cout<<"Withdrawal Could Not Be Done Due To Insufficient Funds In The A/C";
	cout<<"\nPresent A/C Balance Is\t"<<bal<<"\n";
     }
     getch();
 }
 void	bank::deposit(int amt)
 {
     bal+=amt;
 }
int       bank::ret_acno()
{
    return acno;
}

void main()
{
clrscr();

bank b[20];
int n,ch;

do
{
    cout   <<"\nMain Menu"
	   <<"\n1)Add An Account"
	   <<"\n2)Display"
	   <<"\n3)Withdaraw"
	   <<"\n4)Deposit"
	   <<"\n5)Exit";
    cout<<"\n\nenter choice";cin>>ch;
    switch(ch)
    {
    case 1:
	b[n++].enter();
	break;
    case 2:
	{
	    int temp;
	    cout<<"Enter A/C No.\t"; cin>>temp;
	    for(int i=0; i<n;i++)
	    {
		if(b[i].ret_acno()==temp)
		b[i].display();
	    }
	}
	break;
    case 3:
	{
	    int temp,amt;
	    cin>>temp>>amt;
	    for(int i=0; i<n;i++)
	    {
		if(b[i].ret_acno()==temp)
		{
		  b[i].withdraw(amt);
		}
	    }
	}
	break;
    case 4:
	{
	     int temp,amt;
	    cin>>temp>>amt;
	    for(int i=0; i<n;i++)
	    {
		if(b[i].ret_acno()==temp)
		{
		  b[i].deposit(amt);
		}
	    }
	}
	break;
    case 5:
	exit(0);
	break;
    default:cout<<"\ninvalid choice";
    }
    cout<<"\nPress Y to Continue\t";
}while(toupper(getche())=='Y');
}