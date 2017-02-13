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
 cout<<"\nEnter Roll\t";
 cin>>nn->roll;
 nn->next=NULL;
 }

 return nn;
}

class queue
{
node *front,*rear;
public:
queue()
{
 front=rear=NULL;
}

~queue()
{
  while(front)
  {
  del();
  }
}

void insert()
{
 node *nn;
 nn=create_node();
 if(nn)
 {
  if(front)
  {
  rear->next=nn;
  rear=nn;
  }
  else
  front=rear=nn;
 }
 else
  cout<<"Overflow";
}

void del()
{
 node *nn;
 nn=NULL;
 nn=new node;
 if(!front)
  cout<<"Underflow";
 else
  {
  nn=front;
  front=front->next;
  delete nn;
  }
}

void display()
{
 node *nn;
 nn=NULL;
 nn=new node;

 if(!front)
     cout<<"\nUnderflow";
 else
     {
     nn=front;
     while(nn)
      {
      cout<<"\nroll"<<nn->roll;
      nn=nn->next;
      }
     }
}
};
void main()
{
clrscr();
int ch;
queue q;

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
	q.insert();
	break;
    case 2:
	q.del();
	break;
    case 3:
	q.display();
	break;
    default:
	cout<<"Invalid Choice";
    }
  cout<<"\nPress Y to continue:\t";
 }while(toupper(getche())=='Y');
}
