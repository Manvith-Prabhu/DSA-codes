//M Manvith Prabhu
//211EC228
//Quick sort with recursion

#include<iostream>
using namespace std;

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

void Quicksort(int *A,int lb,int ub)
{if(lb<ub)
{int l=partition(A,lb,ub);
Quicksort(A,lb,l-1);
Quicksort(A,l+1,ub);
}}

int main()
{int n;
cout<<"Enter number of elements in array\n";
cin>>n;
int A[n];
cout<<"Enter the elements in the array\n";
for(int i=0;i<n;i++)
cin>>A[i]; 
Quicksort(A,0,n-1);
cout<<"Sorted Array\n";
for(int i = 0; i < n; i++)
cout<<A[i]<<" "; 

return 0;


}