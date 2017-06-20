#include<iostream.h>
#include<conio.h>
#include<ctype.h>

const int N=100;

struct student
{
  int roll;
  char nm[20];
};

class stack
{
student s[N];
int TOP;

public:
 stack()
 {
  TOP=-1;
 }

 ~stack()
 {
  TOP=-1;
 }

 void PUSH()
 {
   if(TOP==N-1)
   cout<<"\nOverflow";
   else
    {
    TOP++;
      cout<<"Enter Roll";	cin>>s[TOP].roll;
      cout<<"Emter Name";	cin>>s[TOP].nm;
    }
 }

 void POP()
 {
   if(TOP==-1)
     cout<<"\nUnderflow";
   else
   {
    TOP--;
   }
 }

 void display()
 {
  if(TOP==-1)
   cout<<"\nUnderflow";
  else
   {
     for(int i=TOP;i>=0;i--)
     {
      cout<<"\nRoll\t"<<s[i].roll;
      cout<<"\nName\t"<<s[i].nm;
     }
   }
 }
};

void main()
{
 clrscr();
 int ch;
 stack S;

 do
 {
  cout<<"\n\tMain Menu:"
      <<"\n1)\tPUSH"
      <<"\n2)\tPOP"
      <<"\n3)\tDISPLAY";
  cout<<"\n\nEnter Choice\t";	cin>>ch;
   switch(ch)
    {
    case 1:
	S.PUSH();
	break;
    case 2:
	S.POP();
	break;
    case 3:
	S.display();
	break;
    default:
	cout<<"Invalid Choice";
    }
  cout<<"\nPress Y to continue:\t";
 }while(toupper(getche())=='Y');
}