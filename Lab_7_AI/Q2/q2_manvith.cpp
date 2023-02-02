//Manvith Prabhu
//211EC228
#include<iostream>
using namespace std;
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
struct Node* newNode(int value) {
  Node* node = new Node;
  node->data = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}
Node* Create_BST(Node* root, int value)
{if(!root)
   root=newNode(value); 
 if(value>root->data)
   root->right=Create_BST(root->right,value);
 else if(value<root->data)
   root->left=Create_BST(root->left,value);
 return root;
}

int height_of_subtree(Node* root)
{ if(root==NULL)
     return 0;
  else return (1+max(height_of_subtree(root->left),height_of_subtree(root->right)));
}

int check_balanced(Node* root)
{if(root==NULL)
 return 1;
 int l=height_of_subtree(root->left);
 int r=height_of_subtree(root->right);
 int dif;
 if(l>r)
  dif=l-r;
 else dif=r-l;
 if(dif<=1&&check_balanced(root->left)==1&&check_balanced(root->right)==1)
   return 1;
 else return 0;
}
int main()
{int A[20],i,n;
 cout<<"Enter the number of elements to be arranged in BST\n";
 cin>>n;
 cout<<"Enter the elements to be organised in BST\n";
 for(i=0;i<n;i++)
 cin>>A[i];
 struct Node* root=newNode(A[0]);
 for(i=1;i<n;i++)
 Create_BST(root,A[i]);
 int flag=check_balanced(root);
 if(flag==1)
 cout<<"BST is balanced";
 else cout<<"BST is not balanced";
 return 0;
}
