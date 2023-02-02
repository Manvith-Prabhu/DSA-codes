//Prime factors using stacks
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ stack<int> S,T;
long int n,i,t;
 cout<<"Enter the number\n";
 cin>>n;
 long int N=n;
 for(i=2;n>1;i++)
  {if(n%i==0)
   {
    while(n%i==0)
     {n=n/i;
     S.push(i);}
   }
  }
cout<<"Prime factors in descending form:\n";
t=S.top();
T.push(t);
cout<<N<<"="<<t;
S.pop();
while(S.empty()!=1)
 {t=S.top();
  cout<<"x"<<t;
 T.push(t);
 S.pop();
 }
cout<<"\nPrime factors in ascending form:\n";
cout<<N<<"="<<T.top();
T.pop();
while(T.empty()!=1)
 { cout<<"x"<<T.top();
 T.pop();
 }
return 0;
}

