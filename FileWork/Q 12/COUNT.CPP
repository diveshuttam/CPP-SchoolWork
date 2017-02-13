#include <iostream.h>
#include <fstream.h>
#include <conio.h>
#include <ctype.h>
#include <process.h>
#include <stdio.h>
#include <string.h>

int  checkpallin(char word[80]);
void create_info();
void vowel_conso();
void sentence_count();
void various_word_count();
void display(char c[80]);

void main()
{
 int choice;
 cout<<"A program To Count Various Things in a file";
 do
 {
 clrscr();
 cout<<"Main Menu"
     <<"\n1)\tCreate Info.txt"
     <<"\n2)\tSentence Count"
     <<"\n3)\tVarious Type Of Word Count"
     <<"\n4)\tCreate File Vovwel.txt & Conso.txt"
     <<"\n5)\tDisplay \'info.txt\'"
     <<"\n6)\tDisplay \'vovwel.txt\'"
     <<"\n7)\tDisplay \'conso.txt\'"
     <<"\n8)\tExit";
 cout<<"\n\nEnter Choice\t";	cin>>choice;

     switch(choice)
     {
     case 1:
	create_info();
	break;
     case 2:
	sentence_count();
	break;
     case 3:
	various_word_count();
	break;
     case 4:
	vowel_conso();
	break;
     case 5:
	display("info.txt");
	break;
     case 6:
	display("vowel.txt");
	break;
     case 7:
	display("conso.txt");
	break;
     case 8:
	exit(0);
	break;
     default:
	cout<<"\nInvalid Choice";
     }
     cout<<"\nPress Y to continue";
 }while(toupper(getche())=='Y');
}

void create_info()
{
 ofstream fout;
 fout.open("info.txt");

 if(!fout)
	cout<<"\nError";
 else
	{
	char line[80];
	char ch;

	do
	  {
	  gets(line);
	  fout<<line;
	  cout<<"\nDo You Want To Enter More??(Y/N)";
	  cin>>ch;
	  }while(toupper(ch)=='Y');

	fout.close();
	}
}

void vowel_conso()
{
   ifstream fin("info.txt");

   ofstream fvowel("vowel.txt");
   ofstream fconso("conso.txt");

   if(!fin||!fvowel||!fconso)
	cout<<"\nError";
   else
	{
	fin.seekg(0);
	char word[80];
	int i=0;
	char ch;
	cout<<"\nMaking Files...\nPress Any key To Continue";
	getch();

	 while(fin.get(ch))
	  {
	  word[i]=ch;
	  if((ch!=' ') && (ch!='.'))
	    {
		i++;
		continue;
	    }
	  word[i++]='\0';

	  i=0;

	   if(isalpha(word[0]))
	    {
	      switch(toupper(word[0]))
		{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		  fvowel<<word<<"\n";
		  break;
		default :
		  fconso<<word<<"\n";
		}
	    }
	 }
	cout<<"\nDone";
	fin.close();
	fvowel.close();
	fconso.close();
	}
}

void sentence_count()
{
  ifstream fin("info.txt");

  if(!fin)
	cout<<"\nError";
  else
	{
	char ch;
	int c=0;
	fin.seekg(0);

	while(fin.get(ch))  	//fullstop as a delimiter
	  {
	  if(ch=='.')
	  c++;
	  }
	cout<<"\nNo of lines\t"<<c;

	fin.close();
	}
}

void various_word_count()
{
 int  pallin=0;
 int  upcase=0;
 char word[80];
 ifstream fin("info.txt");

 if(!fin)
	cout<<"\nerror";
 else
	{
	fin.seekg(0);
	int i=0;
	char ch;
	while(fin.get(ch))
	  {
	  word[i]=ch;
	  if((ch!=' ') && (ch!='.'))
	    {
		i++;
		continue;
	    }
	  word[i++]='\0';

	  i=0;

	  if(checkpallin(word))
		pallin++;

	  if(isupper(word[0]))
		upcase++;
	  }

	fin.close();

	cout<<"\nNo of Pallindrome Words=\t"<<pallin;
	cout<<"\nNo of Uppercase Words=\t\t"<<upcase;
	}
}

void display(char c[20])
{
ifstream fin(c);

if(!fin)
	cout<<"\nError";
else
	{
	char ch;
	fin.seekg(0);
	 while(fin.get(ch))
	   {
	   cout<<ch;
	   }
	fin.close();
	}
}

int checkpallin(char word[80])
{
  int flag=1;
  int n=strlen(word);
  int i=0,j=0;

  for(i=0,j=n-1;i<n/2;i++,j--)
  {
	if(toupper(word[i])!=toupper(word[j]))
	   flag=0;
  }
  return flag;
}