#include<iostream.h>
#include<conio.h>
#include<ctype.h>

#define N 3		//n taken small to verfiy the working

struct student
{
 int roll;
};

int front=-1, rear=-1;
student Q[N];

void insert()
{
 if(front==rear+1 || front==0 && rear==N-1)
	cout<<"\noverflow";
 else
 {
 if(front==-1)
	front=rear=0;
 else
       {
	rear++;
	if(rear==N)
	  rear=0;
       }
 cout<<"Enter Roll:\t";	 cin>>Q[rear].roll;
 }
}

void del()
{
 if(front==-1)
	cout<<"Underflow";
 else
 {
  {
  if(rear==front)
	rear=front=-1;
  else
	front++;
  }

 if(front==N)
  front=0;
 }
}

void display()
{
 int i=0;

 if(front==-1)
  cout<<"Underflow";

 else
 {
 i=front;

 while(i!=rear)
  {
  cout<<"\nRoll\t";
  cout<<Q[i].roll;
  i++;
  if(i==N)
   i=0;
  }
  cout<<"\nRoll\t";
  cout<<Q[rear].roll;
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
