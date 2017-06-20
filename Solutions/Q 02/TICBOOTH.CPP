/****************************************..****************************************/
/****************************************..****************************************/
/****************************************..****************************************/
/****************************************..****************************************/
/****************************************..****************************************/

#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ticbooth
{
private:
  static int nofp;
  static float amt;

public:
  void initialize         ();

  void not_sold       (int people);
  void sold              (int people);

  void display_nofp ();
  void display_both ();
};

//________________________________________________________________________________//
int     ticbooth::nofp;
float  ticbooth::amt;

//________________________________________________________________________________//
void ticbooth::initialize ()
{
 nofp=0;
 amt=0;
}
//________________________________________________________________________________//
void ticbooth::not_sold(int people)
{
 nofp+=people;
 cout<<"\nDone";
}
//.................................................................................................................................................................//
void ticbooth::sold(int people)
{
 nofp+=people;
 amt+=2.5*people;
 cout<<"\nDone";
}
//________________________________________________________________________________//
void ticbooth::display_nofp()
{
 cout<<"\nNo Of People=\t"           <<nofp;
}
//.................................................................................................................................................................//
void ticbooth::display_both()
{
 cout<<"\nNo Of People Visited=\t"<< nofp;
 cout<<"\nNo of Tickets Sold=\t"    << amt/2.5;
}
//________________________________________________________________________________//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//********************************************************************************//
void main()
{
  clrscr();
  cout<<"A PROGRAM TO MANTAIN A TICKETBOOTH AT A FAIR";

  int ch;
  ticbooth t1;
  t1.initialize();

  do
  {
   cout<<"\n\n\nMain Menu"
	  <<"\n\n1)\tPeople Visited"
	  <<"\n2)\tPeople Visited+Ticket Sold"
	  <<"\n3)\tDisplay People"
	  <<"\n4)\tDisplay People Visited+Ticket Sold"
	  <<"\n\nEnter Choice...";    cin>>ch;

      switch(ch)
      {
      case 1:
      {
	int nofp;					//if i dont put brackets error-redeclaration of nofp
	cout<<"\nEnter No. Of People\t";	cin>>nofp;
	t1.not_sold(nofp);
	break;
      }
      case 2:
      {
	int nofp;
	cout<<"\nEnter No. Of People\t";	cin>>nofp;
	t1.sold(nofp);
	break;
      }
      case 3:
	t1.display_nofp();
	break;

      case 4:
	t1.display_both();
	break;

      case 5:
	exit(0);
	break;

      default:
	cout<<"\nInvalid Choice";
      }
      cout<<"\nPress Y To Continue\t";
  }while(toupper(getche())=='Y');
}
//********************************************************************************//