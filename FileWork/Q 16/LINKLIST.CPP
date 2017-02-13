#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>

struct node
{
  int roll;
  node *next;
};

///////////////////////////////////////////////////////////////////////////
node *create_node();
void create_list(node *&start);  //as i am modifying start in the function
				  //without & it did not work
void display(node *start);
void insert(node *&start,node *&temp,int pos);
void del(node *&start,int roll);
void merge(node *&start1,node *&start2,node *&start3);
///////////////////////////////////////////////////////////////////////////

void main()
{
  cout<<"Program to perform basic operations on a linked list";

  int ch;
  node *start1=NULL,*start2=NULL,*start3=NULL;
  do
  {
  clrscr();
  cout<<"\tmain menu"
      <<"\n1)\tCreate List 1"
      <<"\n2)\tInsert"
      <<"\n3)\tDelete"
      <<"\n4)\tDisplay List 1"
      <<"\n5)\tCreate List 2"
      <<"\n6)\tMerge List 1(ASC) and List 2(ASC) in List 3(ASC)"
      <<"\n7)\tDisplay All Lists"
      <<"\n8)\tExit";

  cout<<"\n\nEnter Choice(1-8)";
  cin>>ch;

  switch(ch)
  {
    case 1:
	create_list(start1);
	break;
    case 2:
	{
	node *temp;
	int pos;
	temp=create_node();
	cout<<"Enter Pos\t";
	cin>>pos;
	insert(start1,temp,pos);
	}
	break;
    case 3:
	{
	int roll;
	cin>>roll;
	del(start1,roll);
	}
	break;
    case 4:
	display(start1);
	break;
    case 5:
	create_list(start2);
	break;
    case 6:
	merge(start1,start2,start3);
	break;
    case 7:
    cout<<"\nList1";
	display(start1);
    cout<<"\nList2";
	display(start2);
    cout<<"\nList3";
	display(start3);
	break;
    case 8:
	exit(0);
	break;
  }

  cout<<"\n\nPress Y to Continue\t";
  }while(toupper(getche())=='Y');
}

///////////////////////////////////////////////////////////////////////////
node *create_node()
{
  node *nn;
  nn=NULL;
  nn=new node;
  if(nn)
   {
   cout<<"\n\nEnter Roll\t";
   cin>>nn->roll;
   nn->next=NULL;
   }
   return nn;
}

void create_list(node *&start)
{
node *ptr,*nn;
start=ptr=nn=NULL;

	do
	{
	 nn=NULL;
	 nn=create_node();
	 if(!nn)
		{
		cout<<"Overflow";
		cout<<"Press any key to exit";
		getch();
		exit(0);
		}
	 else
	 {
	 if(start==NULL)
		{
		start=ptr=nn;
		}
	 else
		{
		ptr->next=nn;
		ptr=nn;
		}
	 }
	 cout<<"Press Y to Enter More";
	}while(toupper(getche())=='Y');
}

void display(node *start)
{
node *ptr;
ptr=start;
if(start==NULL)
	cout<<"\nUnderflow";
int i=0;
while(ptr)
  {
  i++;
  cout<<"\nRoll "<<i<<"\t"<<ptr->roll;
  ptr=ptr->next;
  }
}

void insert(node *&start,node *&temp,int pos)
{
  node *ptr=NULL;

  if(pos<1)
  cout<<"\nUnderflow";

  if(pos==1)
  {
   temp->next=start;
   start=temp;
  }

  else
  {
  int i;
  ptr=start;
  for(i=1;i<=pos-2;i++)
    {
    ptr=ptr->next;
    }

    if(ptr!=NULL)
     {
     temp->next=ptr->next;
     ptr->next=temp;
     }
    else
    cout<<"\nOverflow";
  }
}

void del(node *&start,int roll)
{
 node *ptr=NULL;
 node *nn;
 if(start==NULL)
	cout<<"\nUnderflow";
 else
 {
  int flag=0;
   ptr=start;

   while(ptr)
   {
    if(ptr->next->roll==roll)
     {
     nn=ptr->next;
     ptr->next=ptr->next->next;
     delete nn;
     flag=1;
     break;
     }

   ptr=ptr->next;
   }

   if(flag==0)
   {
   cout<<"\nNOT FOUND";
   }

   else
   {
   cout<<"\nDELETED";
   }
 }
}

void merge(node *&start1,node *&start2,node *&start3)
{
 node *ptr1,*ptr2,*ptr3,*nn;
 ptr1=start1;
 ptr2=start2;

 start3=ptr3=nn=NULL;

 while(ptr1!=NULL && ptr2!=NULL)
 {
  nn=new node;
  nn->next=NULL;

  if(ptr1->roll<ptr2->roll)
   {
   nn->roll=ptr1->roll;
   ptr1=ptr1->next;
   }
  else
   {
   nn->roll=ptr2->roll;
   ptr2=ptr2->next;
   }

  if(start3==NULL)
  {
  start3=ptr3=nn;
  }

  else
  {
  ptr3->next=nn;
  ptr3=nn;
  }
 }

 if(ptr1==NULL)
 {
  while(ptr2)
  {
  nn=new node;
  nn->next=NULL;
  nn->roll=ptr2->roll;
  ptr3->next=nn;
  ptr3=nn;
  ptr2=ptr2->next;
  }
 }

 if(ptr2==NULL)
 {
  while(ptr1)
  {
  nn=new node;
  nn->next=NULL;
  nn->roll=ptr1->roll;
  ptr3->next=nn;
  ptr3=nn;
  ptr1=ptr1->next;
  }
 }
}
///////////////////////////////////////////////////////////////////////////