//Header file for Arrays.cpp

void input(int A[],int &n);
void display(int A[],int n);

void display_in_line(int A[],int n);
void swap(int &a,int &b);

void linear_search(int A[],int n,int ele);
void binary_search(int A[],int n,int ele);

void insertion_sort(int A[],int n);
void selection_sort(int A[],int n);
void bubble_sort(int A[],int n);

void insert_sorted(int A[],int &n,int ele);
void insert_unsorted(int A[],int &n,int ele,int pos);

void delete_sorted(int A[],int &n,int ele);
void delete_unsorted(int A[],int &n,int ele);

void merge_sort(int A[],int n,int B[],int m,int C[],int &l);	    //A-Asc+B-Dec=C-Asc
void merge_sort_o_e(int A[],int n,int B[],int m,int C[],int &l);    //odd_even
////////////////////////////////////////////////////////////////////////////
void input(int A[],int &n)
{
int i;
cout<<"\nenter the size of the array(1-20)\t";
cin>>n;
cout<<"\n";
for(i=0;i<n;i++)
 {
 cout<<"Enter element\t"<<i+1<<"\t";
 cin>>A[i];
 }
}

void display(int A[],int n)
{
int i;
cout<<"\n";
for(i=0;i<n;i++)
 {
 cout<<"\nelement\t"<<i+1<<"\t";
 cout<<A[i];
 }
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void display_in_line(int A[],int n)
{
int i;
for(i=0;i<n;i++)
 {
  cout<<A[i]<<" ";
 }
}

void swap(int &a,int &b)
{
 int temp;
 temp=a;
 a=b;
 b=temp;
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void linear_search(int A[],int n,int ele)
{
 int i,flag=0;

 for(i=0;i<n;i++)
 {
  if(A[i]==ele)
   {
    flag=1;
    break;
   }
 }

 if(flag)
  cout<<"\nThe Element Found At\t"<<i+1;
 else
  cout<<"\nElement not found";
}

void binary_search(int A[],int n,int ele)	//for ascending
{
 int flag=0;
 int u=n-1,l=0,mid;

 do
 {
 mid=(u+l)/2;

 if(A[mid]==ele)
  {
   flag=1;
   break;
  }

 else {
       if(A[mid]>ele)
	u=mid-1;
       else
	l=mid+1;
      }
 }while(u>=l);

 if(flag)
  cout<<"\nThe Element Found At\t"<<mid+1;
 else
  cout<<"\nElement not found";
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void insertion_sort(int A[],int n)
{
 int i,j,ele;
 cout<<"\nInitial Array\t   : ";
 display_in_line(A,n);

 i=1;
 while(i<n)
 {
   ele=A[i];
   j=i-1;
   while(A[j]>ele && j>=0)
    {
    A[j+1]=A[j];
    j--;
    }
   A[j+1]=ele;
   cout<<"\nArray After Pass "<<i<<" : ";
   display_in_line(A,n);
   i++;
 }
}

void selection_sort(int A[],int n)
{
 int i,j,*min;

 cout<<"\nInitial Array\t   : ";
 display_in_line(A,n);

 for(i=0;i<n-1;i++)
 {
   min=&A[i];
   for(j=i;j<n;j++)
     {
      if(A[j]<*min)
      min=&A[j];
     }
   swap(A[i],*min);
   cout<<"\nArray After Pass "<<i+1<<" : ";
   display_in_line(A,n);
 }

}

void bubble_sort(int A[],int n)
{
 int i,j;

 cout<<"\nInitial Array\t   : ";
 display_in_line(A,n);

 for(i=0;i<n-1;i++)
    {
	for(j=0;j<n-i-1;j++)
	  if(A[j]>A[j+1])
	   swap(A[j],A[j+1]);

    cout<<"\nArray After Pass "<<i+1<<" : ";
    display_in_line(A,n);
    }
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void insert_sorted(int A[],int &n,int ele)
{
 int i=0,pos;

 cout<<"\nInitial Array\t   : ";
 display_in_line(A,n);

 while(A[i]<ele && i<n)
 {
  i++;
 }

 pos=i;

 for(i=n-1;i>=pos;i--)
 {
  A[i+1]=A[i];
 }

 A[pos]=ele;
 n++;
}

void insert_unsorted(int A[],int &n,int ele,int pos)
{
 int i;

 cout<<"\nInitial Array\t   : ";
 display_in_line(A,n);

 for(i=n-1;i>=pos-1;i--)
 {
  A[i+1]=A[i];
 }

 A[pos-1]=ele;
 n++;
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void delete_sorted(int A[],int &n,int ele)
{
  int i=0,j=0,flag=0;

  for(i=0;i<n;i++)
   {
   if(A[i]==ele)
    {
    flag=1;
    break;
    }

   else if(A[i]>ele)
    break;
   }

   if(flag==1)
   {
    for(j=i;j<n-1;j++)
	A[j]=A[j+1];

    n--;
   }
   else
   cout<<"\nele not found";
}

void delete_unsorted(int A[],int &n,int ele)
{
  int i=0,j=0,flag=0;

  for(i=0;i<n;i++)
   {
   if(A[i]==ele)
     {
     flag=1;
     break;
     }
   }

   if(flag)
   {
   for(j=i;j<n-1;j++)
	A[j]=A[j+1];
    n--;
   }
   else
   cout<<"\nele not found";
}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void merge_sort(int A[],int n,int B[],int m,int C[],int &l)	    //A-Asc+B-Dec=C-Asc
{
 int i=0,j=0,k=0;
 l=m+n;

 for(i=0,j=0,k=m-1;i<l &&j<n && k>=0;i++)
 {
  if(A[j]<B[k])
   {
   C[i]=A[j];
   j++;
   }
  else
  {
   C[i]=B[k];
   k--;
  }
 }

 if(k<0)
  {
  for(;i<l;i++)
    C[i]=A[j++];
  }

 if(j>=n)
  {
  for(;i<l;i++)
  C[i]=B[k--];
  }
}

void merge_sort_o_e(int A[],int n,int B[],int m,int C[],int &l)      //odd_even
{
 if(m==n)
 {
 l=m+n;
 int j=0,k=0,i=0;

 for(i=0;i<l;i++)
  {
  if(i%2==1)	//if odd
   {
   C[i]=A[j++];
   }
  else
   {
   C[i]=B[k++];
   }
  }
 }
 else cout<<"The arrays cannot be merged by odd even as their\n"
	  <<"sizes are not equal";
}
/////////////////////////////////////////////////////////////////////////////