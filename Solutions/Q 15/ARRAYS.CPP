#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <process.h>

#include "g:\bin\programs\filework\Q15\header.h"

void main()
{
  int A[20],B[20],C[20],n,m,l,ele,pos;

  int flag=0;
  char choice;
  int  choice1;

  do
  {
  clrscr();
  cout<<"\tMain Menu"
      <<"\na.\tInput"
      <<"\nb.\tDisplay"
      <<"\nc.\tSearch"
      <<"\nd.\tSort"
      <<"\ne.\tInsert"
      <<"\nf.\tDelete"
      <<"\ng.\tMerge Sort"
      <<"\nh.\tExit";

  cout<<"\n\nEnter Choice(a to h):\t";		cin>>choice;

  switch(choice)
  {
  case 'a':
	input(A,n);	//n passed by reference
	flag=1;
	break;
  case 'b':
	if(flag)
	display(A,n);
	else
	cout<<"\nArray Not Entered";
	break;
  case 'c':
	if(flag)
	{
	 cout<<"\nSubmenu\n"
	     <<"\n1)\tLinear Search"
	     <<"\n2)\tBinary Search";

	 cout<<"\nEnter Choice\t";	cin>>choice1;

	 cout<<"\nEnter Element\t";
	 switch(choice1)
	 {
	 case 1:
		cin>>ele;
		linear_search(A,n,ele);
		break;
	 case 2:
		cin>>ele;
		binary_search(A,n,ele);
		break;
	 default:
		cout<<"\nInvalid Choice";
	 }

	}
	else
	 cout<<"\nArray Not Entered";
	break;
  case 'd':
	if(flag)
	{
	 cout<<"\nSubmenu\n"
	     <<"\n1)\tInsertion Sort"
	     <<"\n2)\tSelection Sort"
	     <<"\n3)\tBubble Sort";

	 cout<<"\nEnter Choice\t";	cin>>choice1;

	 switch(choice1)
	 {
	 case 1:
		insertion_sort(A,n);
		break;
	 case 2:
		selection_sort(A,n);
		break;
	 case 3:
		bubble_sort(A,n);
		break;
	 default:
		cout<<"\nInvalid Choice";
	 }

	 cout<<"\nFinal Array\t     ";
	 display_in_line(A,n);
	}
	else
	 cout<<"\nArray Not Entered";
	break;
  case 'e':
	if(flag)
	{
	 cout<<"\nSubmenu\n"
	     <<"\n1)\tInsert in Sorted"
	     <<"\n2)\tInsert in Unsorted";

	 cout<<"\nEnter Choice\t";	cin>>choice1;

	 cout<<"\nEnter Element\t";

	 switch(choice1)
	 {
	 case 1:
		cin>>ele;
		insert_sorted(A,n,ele);
		break;
	 case 2:
		cin>>ele;

		do
		{
		cout<<"\nEnter Position";	cin>>pos;

		if(pos<1 || pos>n+1)
		  cout<<"\nInvalid Position! Please Enter Again.\n\n";
		}while(pos<1 || pos>n+1);

		insert_unsorted(A,n,ele,pos);
		break;
	 default:
		cout<<"\nInvalid Choice";
	 }
	 cout<<"\nFinal   Array\t   : ";
	 display_in_line(A,n);
	}
	else
	 cout<<"\nArray Not Entered";
	break;
  case 'f':
	if(flag)
	{
	 cout<<"\nSubmenu\n"
	     <<"\n1)\tDelete in Sorted"
	     <<"\n2)\tDelete in Unsorted";

	 cout<<"\nEnter Choice\t";	cin>>choice1;

	 cout<<"\nEnter Element\t";

	 switch(choice1)
	 {
	 case 1:
		cin>>ele;
		cout<<"\nArray Before Delete\n";
		display_in_line(A,n);
		delete_sorted(A,n,ele);
		cout<<"\nArray After Delete\n";
		display_in_line(A,n);
		break;
	 case 2:
		cin>>ele;
		cout<<"\nArray Before Delete\n";
		display_in_line(A,n);
		delete_sorted(A,n,ele);
		cout<<"\nArray After Delete\n";
		display_in_line(A,n);
		break;
	 default:
		cout<<"\nInvalid Choice";
	 }
	}
	else
	 cout<<"\nArray Not Entered";
	break;
  case 'g':
	if(flag)
	 {
	 cout<<"\nEnter Array B";
	 input(B,m);
	 cout<<"\nSubmenu\n"
	     <<"\n1)\tMerge Sort(A Asc+ B Desc= C Asc)"
	     <<"\n2)\tMerge A at Odd and B at Even in C";

	 cout<<"\nEnter Choice\t";	cin>>choice1;

	 switch(choice1)
	  {
	  case 1:
		merge_sort(A,n,B,m,C,l);
		cout<<"A\t";
		display_in_line(A,n);
		cout<<"\nB\t";
		display_in_line(B,m);
		cout<<"\nC\t";
		display_in_line(C,l);
		break;

	  case 2:
		merge_sort_o_e(A,n,B,m,C,l);
		cout<<"A\t";
		display_in_line(A,n);
		cout<<"\nB\t";
		display_in_line(B,m);
		cout<<"\nC\t";
		display_in_line(C,l);
		break;
	  default:
		cout<<"Invalid Choice";
	  }
	 }
	 else
	   cout<<"Array Not Entered!";

	break;
  case 'h':
	exit(0);
  default :
	cout<<"Invalid Choice\n";
  }

  cout<<"\nPress Y To Continue\t";

  }while(toupper(getche())=='Y');
  getch();
}