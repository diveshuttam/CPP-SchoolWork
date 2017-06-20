#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>

struct node
{
  char ch;
  node *next;
};

node *TOP=NULL;

node *create_node(char ch1)
{
  node *nn;
  nn=NULL;
  nn=new node;

  if(nn)
  {
  nn->ch=ch1;
  nn->next=NULL;
  }

  return nn;
}

void PUSH(char *&str)
{
 node*nn;

 int i=0;

 do
 {
 nn=create_node(str[i]);
  if(nn)
   {
     nn->next=TOP;
     TOP=nn;
   }
  else
   cout<<"\noverflow";
   i++;
 }while(str[i]!='\0');
}

void POP(char *&str)
{
  node*nn;
  nn=new node;
  int i=0;
  do
  {
  if(TOP==NULL)
    cout<<"\nUnderflow";
  else
  {
   if(nn)
    {
     str[i]=TOP->ch;
     //cout<<"\nTOP"<<TOP->ch;
     nn=TOP;
     TOP=TOP->next;
     delete nn;
    }

   else
    cout<<"\nError Temp Node Cannot Be Created";
  }
  i++;
  }while(TOP);

  str[i]='\0';
}

void main()
{
 clrscr();

 cout<<"A Program to find whether a string is pallindrome or not using stacks";

 char *str,*str1;
 str=new char[80];
 str1=new char[80];

 cout<<"\n\nEnter a String:\t";
 gets(str);

 PUSH(str);
 POP(str1);

 cout<<"\n"<<str;
 cout<<"\n"<<str1;

 if(strcmpi(str,str1)==0)
 cout<<"\nPallindrome";
 else
 cout<<"\nNot Pallindrome";
 getch();
}