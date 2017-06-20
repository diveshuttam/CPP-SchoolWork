/*******************************************************************************/
/***************************Name:- Divesh Uttamchandani***************************/
/***************************Class :- XII  A                           ***************************/
/***************************Date  :- 07 July 2014                ***************************/
/***************************Q-1)  :- Complex Numbers      ***************************/
/*******************************************************************************/
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>

int bk_no=1000;
int n=0;

class stock
{
private:
 int   bk_no;
 float price;
 char  pub[20],aut[20],title[20];
 int   noc;
public:
  stock()
  {
  ;
  }

  void enter()
  {
  bk_no=::bk_no++;
  cout<<"\nEnter book title:\t";     	cin>>title;
  cout<<"\nEnter book price:\t";     	cin>>price;
  cout<<"\nEnter author name:\t";    	cin>>aut;
  cout<<"\nEnter publisher name:\t";	cin>>pub;
  cout<<"\nEnter stock:";		cin>>noc;
  }

  void display()
  {
  cout<<"\nbook title:\t";     	cout<<title;
  cout<<"\nbook price:\t";     	cout<<price;
  cout<<"\nauthor name:\t";    	cout<<aut;
  cout<<"\npublisher name:\t";	cout<<pub;
  }

  void gettitle(char A[])
  {
  strcpy(A,title);
  }

  void getaut(char A[])
  {
  strcpy(A,aut);
  }

  void checkcopies(int A)
  {
  if(A>noc)
	cout<<"\nSorry These Many Copies Are Not Availible";
  else
   {
   cout<<"\nDone\n Total Amount=\t"<<price*A;
   noc-=A;
   }
  }

  ~stock()
  {
  cout<<"\ndestructing";
  }
};

void main()
{
 clrscr();
 int ch;

  stock S[100];

  do
  {
   cout<<"\n\nMain Menu\n"
	  <<"\n1)\tAdd A Book"
	  <<"\n2)\tDisplay A Book"
	  <<"\n3)\tSell A Book"
		    <<"\n4)\tExit"
		    <<"\n\nEnter Choice...";    cin>>ch;

      switch(ch)
      {
      case 1:
	  S[n++].enter();
	  break;

      case 2:
       {
	  char A[20],B[20],temp1[20],temp2[20];
	  cout<<"\nEnter Title\t";      cin>>A;
	  cout<<"\nEnter  Author\t";  cin>>B;
	  for(int i=0;i<n;i++)
	  {

	      S[i].gettitle(temp1);
	      S[i].getaut(temp2);
	      if(strcmpi(A,temp1)==0)
		 if(strcmpi(B,temp2)==0)
		    break;
	  }
	  if(i<n)
	  S[i].display();
	  else
	    cout<<"sorry book was not found";
	  break;
       }

      case 3:
	      {
	  char A[20],B[20],temp1[20],temp2[20];
	  int noc;
	  cout<<"\nEnter Title\t";      cin>>A;
	  cout<<"\nEnter  Author\t";  cin>>B;
	  for(int i=0;i<n;i++)
	  {
	      S[i].gettitle(temp1);
	      S[i].getaut(temp2);
	      if(strcmpi(A,temp1)==0)
		 if(strcmpi(B,temp2)==0)
		    break;
	  }
	  if(i<n)
	  {
	  S[i].display();
	  cout<<"\nenter no of copies\t";    cin>>noc;
	  S[i].checkcopies(noc);
	  }
	  else
	    cout<<"\n sorry book not found";
	  break;
       }

      case 4:
	exit(0);
	break;

      default:
	cout<<"Invalid Choice";
      }

  cout<<"\n\nPress 'Y' to Continue...";

  }while(toupper(getche())=='Y');
}
