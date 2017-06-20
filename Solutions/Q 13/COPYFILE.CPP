#include<fstream.h>
#include<stdio.h>
#include<conio.h>

void copy(char dest[20],char source[20]);

void main()
{
 char file1[20],file2[20];
 cout<<"\nenter file1";
 gets(file1);
 cout<<"\nenter file 2";
 gets(file2);
 copy(file2,file1);
 getch();
}

void copy(char dest[20],char source[20])
{
 ofstream fout(dest,ios::trunc|ios::noreplace);
 ifstream fin(source);

 if(!fout||!fin)
 cout<<"\nerror";
 else
  {
  fin.seekg(0);
  char ch;
      while(fin.get(ch))
      {
      fout.put(ch);
      }
  }
  fin.close();
  fout.close();
}