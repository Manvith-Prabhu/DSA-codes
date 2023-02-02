#include<iostream>

using namespace std;

void merge(int *A,int lb,int mid,int ub){
int n=ub-lb+1;
int B[n];
int i=lb,j=mid+1,k=0;
while(i<=mid&&j<=ub)
{
    if(A[i]<A[j]){
        B[k] = A[i];
        i++;
    }
    else{
        B[k] = A[j];
        j++;
    }
k++;
}
if(i==mid+1)
{
    for(j;j<=ub;j++)
    {
        B[k]=A[j];
        k++;
    }
}
else if(j==ub+1)
{
    for(i;i<=mid;i++)
    {
    B[k]=A[i];
     k++;
    }
}

for(int t=0;t<n;t++)
A[lb+t]= B[t];
}

void mergeSort(int *A,int lb,int ub)
{if(lb < ub)
{
int mid=(lb+ub)/2;
mergeSort(A,lb,mid);
mergeSort(A,mid+1,ub);
merge(A,lb,mid,ub);
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
mergeSort(A,0,n-1);
cout<<"Sorted Array\n";
for(int i = 0; i < n; i++)
cout<<A[i]<<" "; 

return 0;
}



