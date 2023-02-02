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

void inorder(struct Node *root) {
  if (root == NULL) return;
  inorder(root->left);
  cout<<(root->data)<<" ";
  inorder(root->right);
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
 cout<<"Keys of BST in arranged order\n";
 inorder(root);
 return 0;
}