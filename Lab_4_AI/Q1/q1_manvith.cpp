#include<iostream>
#include<cstring>
#define n 40
using namespace std;

struct stck
  {char s[n];
   int top;
  };
 
int main()
{stck a;
 void push(char,stck*);
 void pop(stck*);
char exp[n];
int i;
a.top=-1;
cout<<"Write the expression\n";
cin>>exp;
int m=strlen(exp);
for(i=0;i<m;i++)
{if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
 push(exp[i],&a);
else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
 { if(exp[i]==')')
  {if(a.s[a.top]=='(')
    pop(&a); 
   else
  {cout<<"\nExpression is unbalanced\n";
   goto x;}
  }
 if(exp[i]=='}')
 {if(a.s[a.top]=='{')
    pop(&a); 
  else
    {cout<<"\nExpression is unbalanced\n";
     goto x;}
 }
 if(exp[i]==']')
 {if(a.s[a.top]=='[')
   pop(&a);
  else
   {cout<<"\nExpression is unbalanced\n";
    goto x;}
 }}
 }
if(a.top==-1)
cout<<"\nExpression is balanced\n";
x:return 0;
}
void push(char c,stck *a)
 {if(a->top==(n-1))
  cout<<"Overflow";
 else
 {a->top++;
 a->s[a->top]=c;
 }}

 void pop(stck *a)
  {if(a->top==-1)
 cout<<"Underflow\n";
  else
   a->top--;}