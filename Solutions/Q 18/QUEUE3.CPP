#include<iostream.h>
#include<conio.h>
#include<ctype.h>

const int N=50;

struct student
{
 int roll;
};

int front=-1, rear=-1;
student Q[N];

void insert()
{
 if(rear==N-1)
	cout<<"overflow";
 else
 {
 if(front==-1)
	front=rear=0;
 else
	rear++;
 cout<<"\nEnter Roll:\t";
 cin>>Q[rear].roll;
 }
}

void del()
{
 if(front==-1)
	cout<<"Underflow";
 else
 {
 if(rear==front)
	rear=front=-1;
 else
  front++;
 }
}

void display()
{
 if(front==-1)
  cout<<"Underflow";
 else
 {
 int i;
 for(i=front;i<=rear;i++)
  {
  cout<<"\nRoll\t";
  cout<<Q[i].roll;
  }
 }
}

void main()
{
clrscr();
int ch;

do
 {
  cout<<"\n\tMain Menu:"
      <<"\n1)\tINSERT"
      <<"\n2)\tDELETE"
      <<"\n3)\tDISPLAY";
  cout<<"\n\nEnter Choice\t";	cin>>ch;
   switch(ch)
    {
    case 1:
	insert();
	break;
    case 2:
	del();
	break;
    case 3:
	display();
	break;
    default:
	cout<<"Invalid Choice";
    }
  cout<<"\nPress Y to continue:\t";
 }while(toupper(getche())=='Y');
}
