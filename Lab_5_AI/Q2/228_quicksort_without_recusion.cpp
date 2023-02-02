//M Manvith Prabhu
//211EC228
//Quicksort withpout recursion

#include<iostream>
using namespace std;
 
void swap(int* x, int* y)
{
int t =*x;
*x=*y;
*y=t;
}

int partition(int *A,int lb,int ub)
{int pivot=A[lb];
int start=lb;
int end=ub;
while(start<end)
{while(A[start]<=pivot&&start<ub)
  start++;
  while(A[end]>pivot)
   end--;
if(start<end)
 {int t=A[start];
 A[start]=A[end];
 A[end]=t;
 }
}
if(start>=end)
{int t=A[end];
A[end]=A[lb];
A[lb]=t;
}
return end;
}
void quicksort(int *A,int lb,int ub)
{
int stack[ub-lb+1];
int top=-1;
top++;
stack[top]=lb;
top++;
stack[top]=ub;
while(top>=0) {
ub=stack[top];
top--;
lb=stack[top];
top--;
int l=partition(A,lb,ub);
if(l-1>lb) 
{top++;
stack[top] = lb;
top++;
stack[top] =l-1;
}
if(l+1<ub) 
{top++;
stack[top]=l+1;
top++;
stack[top]=ub;
}
}
}

int main()
{int n;
cout<<"Enter number of elements in array\n";
cin>>n;
int A[n];
cout<<"Enter the elements in the array\n";
for(int i=0;i<n;i++)
cin>>A[i]; 
quicksort(A,0,n-1);
cout<<"Sorted Array\n";
for(int i=0;i<n;i++)
cout<<A[i]<<" ";
return 0;
}