#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int main()
{stack<string> a;
 string ip;
 cout<<"Enter a sentence\n";
 getline(cin,ip);
 int i;
 string op="";
 for(i=0;i<ip.length();i++)
 {
  if(ip[i]==' ')
  {a.push(op);
  op="";}
  else
  op=op+ip[i];
 }
 a.push(op);

 while(a.empty()!=1)
 {op=a.top();
 cout<<op<<" ";
 a.pop();
 }
return 0;
}