//Manvith Prabhu
//211EC228
#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>
using namespace std;
struct Node {
  char data;
  struct Node *left;
  struct Node *right;
};

struct Node* newNode(char data) {
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int evaluate(struct Node* root)
{
  if (!root->left&& !root->right)
    return (root->data);
  int l_val = evaluate(root->left);
  int r_val = evaluate(root->right);
  if (root->data == '+')
    return (l_val+r_val);
  if (root->data == '-')
    return (l_val -r_val);
  if (root->data == '*')
    return (l_val*r_val);
  if (root->data == '/')
    return (l_val/ r_val);
}


struct Node* constructTree(string &s)
{ stack<Node*> N;
  stack<int> C;
  Node *t=new Node;
  Node* t1=new Node;
  Node* t2=new Node;
  
  int p[123] = { 0 };
    p['+'] = p['-'] = 1;
    p['/'] = p['*'] = 2;
    p['^'] = 3;
    p[')'] = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') {
            C.push(s[i]);
        }

        else if (isdigit(s[i]))
        {   string x;
            int j;
            for(j=0;isdigit(s[i+j]);j++)
             x[j]=s[i+j];
            int num=stoi(x);
            t = newNode(num);
            N.push(t);
            i=i+j-1;
            x={0};
        }
        
        else if (p[s[i]] > 0)
        {
            while (!C.empty()&&C.top()!='('&& ((s[i]!='^'&&p[C.top()]>=p[s[i]])||(s[i]=='^'&&p[C.top()]>p[s[i]])))
             { 
                t = newNode(C.top());
                C.pop();

                t1 = N.top();
                N.pop();

                t2 = N.top();
                N.pop();

                t->left = t2;
                t->right = t1;
                N.push(t);
            }

            C.push(s[i]);
        }
        else if (s[i] == ')') {
            while (!C.empty() && C.top() != '(')
            {
                t = newNode(C.top());
                C.pop();
                t1 = N.top();
                N.pop();
                t2 = N.top();
                N.pop();
                t->left = t2;
                t->right = t1;
                N.push(t);
            }
            C.pop();
        }
    }
    t = N.top();
    return t;
    
}

int main()
{string exp;
cout<<"Enter the expression to be evaluated\n";
cin>>exp;
exp= "("+exp+")";
Node* root=new Node;
root=constructTree(exp);
int value=evaluate(root);
cout<<"Value of expression= "<<value;

return 0;
}