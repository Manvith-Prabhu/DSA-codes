//Manvith prabhu
//211EC228
#include <iostream>
using namespace std;
struct Node {
  char value;
  struct Node *left;
  struct Node *right;
};

struct Node* newNode(char value) {
  Node* node = new Node;
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}
void preorder(struct Node *root) {
  if (root == NULL) return;
  cout<<(root->value)<<" ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(struct Node *root) {
  if (root == NULL) return;
  inorder(root->left);
  cout<<(root->value)<<" ";
  inorder(root->right);
}

void postorder(struct Node *root) {
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  cout<<(root->value)<<" ";
}

int main()
{
struct Node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->left = newNode('F');
    root->right->right = newNode('G');

    cout<<"Tree in Preorder:\n";
    preorder(root);
    cout<<"\nTree in Inorder:\n";
    inorder(root);
    cout<<"\nTree in Postorder:\n";
    postorder(root);

    return 0;
}
