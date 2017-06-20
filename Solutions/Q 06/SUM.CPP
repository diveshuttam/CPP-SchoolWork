/*******************************************************************************/
/***************************Name:- Divesh Uttamchandani***************************/
/***************************Class :- XII  A                           ***************************/
/***************************Date  :- 07 July 2014                ***************************/
/***************************Q-1)  :- Complex Numbers      ***************************/
/*******************************************************************************/
#include<iostream.h>
#include<conio.h>
#include<ctype.h>

int sum(int A[20],int n)
{
int s=0;
for(int i=0;i<n;i++)
 {
 s+=A[i];
 }
return s;
}

int sum(int A[20],int n,char a)
{
int temp=-1,s=0;

if(toupper(a)=='O')
temp=1;

if(toupper(a)=='E')
temp=0;

for(int i=0;i<n;i++)
 {
 if(A[i]%2==temp)
   s+=A[i];
 }
return s;
}
void main()
{
clrscr();
int A[20],n,i;
cout<<"Enter SIze Of Array\t";
cin>>n;
cout<<"\n";
for(i=0;i<n;i++)
{
cout<<"Enter Element  "<<i+1<<"\t";
	cin>>A[i];
}
cout<<"\nsum(A,n)\t"<<sum(A,n);
cout<<"\nsum(A,n,'e')\t"<<sum(A,n,'e');
cout<<"\nsum(A,n,'o')\t"<<sum(A,n,'o');
cout<<"\nsum(A,n,'x')\t"<<sum(A,n,'x');

getch();
}
