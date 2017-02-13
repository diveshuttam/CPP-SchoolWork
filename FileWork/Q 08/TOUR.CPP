#include<iostream.h>
#include<conio.h>
#include<string.h>

class tour
{
private:
 char   TCode[20];
 int    NoofAdults;
 int    NoofKids;
 int    Kilometres;
 float  TotalFare;
public:
tour()
 {
  strcpy(TCode,"NULL");
  NoofAdults=0;
  NoofKids=0;
  Kilometres=0;
  TotalFare=0;
 }
void AssignFare()
 {
  if(Kilometres<1000)
    if(Kilometres<500)
     TotalFare=300*NoofAdults+150*NoofKids;
    else
     TotalFare=200*NoofAdults+100*NoofKids;
  else
   TotalFare=500*NoofAdults+250*NoofKids;
 }
void EnterTour()
{
 cout<<"\nTCode\t";  	cin>>TCode;
 cout<<"\nNoofAdults\t"; 	cin>>NoofAdults;
 cout<<"\nNoofKids\t";  	cin>>NoofKids;
 cout<<"\nKilometres\t";	cin>>Kilometres;
 AssignFare();
}
void ShowTour()
 {
 cout<<"\nTCode\t";  	cout<<TCode;
 cout<<"\nNoofAdults\t";  cout<<NoofAdults;
 cout<<"\nNoofKids\t";  	cout<<NoofKids;
 cout<<"\nKilometres\t";	cout<<Kilometres;
 cout<<"\nTotal Amount\t"; cout<<TotalFare;
 }
};

void main()
{
clrscr();
tour T;
T.EnterTour();
cout<<"\n\n";
T.ShowTour();
getch();
}
