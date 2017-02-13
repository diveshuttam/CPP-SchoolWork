/*******************************************************************************/
/***************************Name:- Divesh Uttamchandani***************************/
/***************************Class :- XII  A                           ***************************/
/***************************Date  :- 07 July 2014                ***************************/
/***************************Q-1)  :- Complex Numbers      ***************************/
/*******************************************************************************/

#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>

///////////////////////////////////////////// Declaration & Definition of Class ////////////////////////////////////////////////
class complex
{
private:
  float   r;
  float   i;

public:
  void	enter    ();
  void	display ();

  void	add_e  (complex c1,complex c2);
  complex	add_i   (complex c);

  void	mul_e  (complex c1,complex c2);
  complex	mul_i   (complex temp);

  void	sub_e  (complex c1,complex c2);
  complex	sub_i   (complex temp);
};


//______________________________________________________________________________//
void complex::enter()
{
 cout<<"Enter Real Part\t\t";      cin>>r;
 cout<<"Enter Imaginary Part\t"; cin>>i;
}
//............................................................................................................................................................//
void complex::display()
{
 cout<<r;
 if(i>=0)cout<<"+";
 cout <<i<<"i";
}
//______________________________________________________________________________//






//______________________________________________________________________________//
void complex::add_e(complex c1,complex c2)
{
    r=c1.r+c2.r;
    i=c1.i+c2.i;
}
//............................................................................................................................................................//
complex complex::add_i(complex c)
{
 complex temp;
 temp.r=r+c.r;
 temp.i=i+c.i;
 return temp;
}
//______________________________________________________________________________//
void complex::mul_e(complex c1,complex c2)
{
    r=c1.r*c2.r-c1.i*c2.i;
    i=c1.r*c2.i+c1.i*c2.r;
}
//............................................................................................................................................................//
complex complex::mul_i(complex c)
{
 complex temp;
 temp.r=r*c.r-i*c.i;
 temp.i=r*c.i+i*c.r;
 return temp;
}
//______________________________________________________________________________//
void complex::sub_e(complex c1,complex c2)
{
    r=c1.r-c2.r;
    i=c1.i-c2.i;
}
//............................................................................................................................................................//
complex complex::sub_i(complex c)
{
 complex temp;
 temp.r=r-c.r;
 temp.i=i-c.i;
 return temp;
}
//______________________________________________________________________________//
////////////////////////////////////////////////////  End Of Class Defination //////////////////////////////////////////////////////







//**********************************Void Main()**********************************//
void main()
{
  clrscr();
  int ch;
  complex c1,c2,r;

  cout<<"Enter First Number\n";             c1.enter();
  cout<<"\nEnter Second Number\n";      c2.enter();

  do
  {
   cout<<"\n\nMain Menu\n"
	  <<"\n1)\tAdd"
	  <<"\n2)\tMultiply"
	  <<"\n3)\tSubtract"
              <<"\n4)\tExit"
              <<"\n\nEnter Choice...";    cin>>ch;
      switch(ch)
      {
      case 1:
	r.add_e(c1,c2);           //explicit call
	r.display();
	cout<<"\n";
	r=c1.add_i(c2);           //implicit call
	r.display();
	break;
      case 2:
	r.mul_e(c1,c2);           //explicit call
	r.display();
	cout<<"\n";
	r=c1.mul_i(c2);           //implicit call
	r.display();
	break;
      case 3:
	r.sub_e(c1,c2);           //explicit call
	r.display();
	cout<<"\n";
	r=c1.sub_i(c2);           //implicit call
	r.display();
	break;
      case 4:
	exit(0);
	break;
      default:
	cout<<"Invalid Choice";
      }
  cout<<"\n\nPress 'Y' to Continue...";
  }while(toupper(getche())=='Y');
}
//********************************End Of Main***********************************//
