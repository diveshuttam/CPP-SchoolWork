#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
int e=1 ;

class employee
{protected:
int e_no;
char nm[20];
char add[20];
char dep[20];
public:
void enter()
{cout<<"\n\nEnter employee name\t\t";
gets(nm);
cout<<"Enter employee address\t\t";
gets(add);
cout<<"Enter employee department\t";
gets(dep);
e_no=e++;
cout<<"\nEmployee no alloted="<<e_no<<"\n";
}
void display()
{
 cout<<"\nEmployee no:\t\t"<<e_no;
 cout<<"\nEmployee name:\t\t"<< nm;
 cout<<"\nEmployee department:\t"<< dep;
 cout<<"\nEmployee address:\t"<< add;
}
};

class manager:employee	//manager IS-A employee
{
employee e[20];
int no_of_e;            //it HAS details of emp working under the manager
public:
void enter()
 {
 cout<<"Enter info of manager\n\n";
 employee::enter();
 cout<<"\nEnter no of employees working under\t";
 cin>>no_of_e;

	for(int i=0;i<no_of_e;i++)
	{
	cout<<"\n\nEnter details of employee\t"<<i+1;
	e[i].enter();
	}
 }
 void display()
 {
  cout<<"\nInfo Of Manager";
  employee::display();
  cout<<"\n\nNo of employee working under\t"<<no_of_e;
  for(int i=0;i<no_of_e;i++)
   {
   cout<<"\n\nDetails of employee\t"<<i+1;
   e[i].display();
   }
 }
};

void main()
{
clrscr();
manager m;
m.enter();
cout<<"\n\n\n";
cout<<"Press any key to see details...";
getch();
clrscr();
m.display();
getch();
}