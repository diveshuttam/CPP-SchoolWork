#include<iostream.h>
#include<conio.h>
#include<ctype.h>

struct node
{
  int roll;
  node *next;
};

node *create_node()
{
  node *nn;
  nn=NULL;
  nn=new node;
  if(nn)
  {
  cout<<"\nEnter roll\t";
  cin>>nn->roll;
  nn->next=NULL;
  }
  return nn;
}

class stack
{
node *TOP;

public:
 stack()
 {
  TOP=NULL;
 }

 ~stack()
 {
  while(TOP)
   {
   POP();
   }
 }

 void PUSH()
 {
  node*nn;
  nn=create_node();
   if(nn)
    {
      nn->next=TOP;
      TOP=nn;
    }
   else
    cout<<"\noverflow";
 }

 void POP()
 {
   node*nn;
   nn=new node;
   if(TOP==NULL)
     cout<<"\nUnderflow";
   else
   {
    if(nn)
     {
      nn=TOP;
      TOP=TOP->next;
      delete nn;
     }

    else
     cout<<"\nError Temp Node Cannot Be Created";
   }
 }

 void display()
 {
  node *ptr;
  ptr=new node;
  ptr=TOP;
  if(TOP==NULL)
   cout<<"\nUnderflow";
  else
   {
     while(ptr)
     {
      cout<<"\nRoll\t"<<ptr->roll;
      ptr=ptr->next;
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