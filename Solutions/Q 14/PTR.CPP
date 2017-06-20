#include<iostream.h>
#include<stdio.h>
#include<conio.h>

char *substr(char *str1,char *str2)
{
 int i=0,j=0,flag=0;
 char *ptr=NULL;
 ptr=new char[80];

 for(i=0;str1[i]!='\0';i++)
 {
 j=0;
  if(str1[i]==str2[0])
   {
    do
     {
      j++;
      if(str2[j]=='\0')
       {
       flag=1;
       ptr=str1+i;
       break;
       }
     }while(str1[i+j]==str2[j]);
   }

   if(flag==1)
   break;
 }

 if(flag)
 return ptr;
 else
 return NULL;
}

void main()
{
 clrscr();
 char *str1,*str2,*t;
 str1=new char[80];
 str1=new char[80];

 cout<<"\nA Program to Find a Substring In the Main String";

 cout<<"\nEnter String 1(Main String)";
 gets(str1);

 cout<<"\nEnter String 2(Substring to be searched for)";
 gets(str2);

 t=substr(str1,str2);

 printf("%s",t);                //as cout and puts did not print NULL

 getch();
}