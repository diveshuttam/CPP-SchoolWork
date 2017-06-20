//-----------------------------including directeries-----------------------------------------
#include<iostream.h>
#include<conio.h>
#include<process.h>
//------------------------------dec. & def. of class-----------------------------------------
class date
{
private:
    int mm,dd,yyyy;
    int check_leap(int yyyy);
    int days_in_month(int mm,int yyyy);
    int check_valid(int dd,int mm,int yyyy);
    int abs(int a);
public:
    void enter();
    void display();
    date newdate(date,int);
};

int date::check_leap(int yyyy)
{
    if(yyyy%4==0&&yyyy%100!=0||yyyy%400==0)
	return 1;
    else
	return 0;
}

int date::days_in_month(int mm,int yyyy)
{
    switch(mm)
    {
    case 2:
	{
	    if(check_leap(yyyy)==1) //if year is leap
		return 29;
	    else
		return 28;
	}
    case 4:
    case 6:
    case 9:
    case 11: return 30;
    default: return 31;
    }
}

int date::check_valid(int dd,int mm,int yyyy)
{
   int flag=0;
   if(yyyy>0)
    if(mm>0&&mm<=12)
      if(dd>0&&dd<=days_in_month(mm,yyyy))
      flag=1;
   return flag;
}

int date::abs(int a)
{
    if(a<0)
	a=-1*a;
    return a;
}

void date::enter()
{
    cout<<"\nenter date(dd)\t\t";    cin>>dd;
    cout<<"enter month(mm)\t\t";     cin>>mm;
    cout<<"enter year(yyyy)\t";    cin>>yyyy;
}

void  date::display()
{
    cout<<dd<<"/"<<mm<<"/"<<yyyy;
}

date date::newdate(date dt,int days_add)
{
date new_dt;
new_dt=dt;

if(check_valid(dt.dd,dt.mm,dt.yyyy)==1)  //if date entered is valid
{
if(days_add<0)
    {
	for(int i=1;i<=abs(days_add);i++)
	    {
	    new_dt.dd--;
	    if(new_dt.dd<1)
	    {
	    new_dt.mm--;
	    if(new_dt.mm<1)
		{
		    new_dt.mm=12;
		    new_dt.yyyy--;
		}
		new_dt.dd=days_in_month(new_dt.mm,new_dt.yyyy);
	    }
	    }
	}

	//if added
	if(days_add>0)
	{
	for(int i=1;i<=abs(days_add);i++)
	    {
		new_dt.dd++;
		if(new_dt.dd>days_in_month(new_dt.mm,new_dt.yyyy))
		    {
			new_dt.dd=1;
			new_dt.mm++;
			    if(new_dt.mm>12)
				    {
				    new_dt.mm=1;
				    new_dt.yyyy++;
				    }
		    }
	    }
	}
}
else
    {
	cout<<"\ninvalid date press any key to exit";
	getch();
	exit(0);
    }
return new_dt;
}


//-------------------------------------main---------------------------------------------------
void main()
{
    clrscr();
    int days_add;
    date dt,new_dt;

    cout<<"Enter Date\n";
    dt.enter();

    cout<<"\nEnter Days To Be Added Or Subtracted\t";
    cin>>days_add;

    new_dt=new_dt.newdate(dt,days_add);
    cout<<"Your new date is ";
    new_dt.display();

    getch();
}

