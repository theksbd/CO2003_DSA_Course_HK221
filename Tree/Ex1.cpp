#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(const int &data)
  {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

class BinaryTree
{
public:
  Node *root;

protected:
  int getSizeRec(Node *);

public:
  BinaryTree()
  {
    this->root = NULL;
  }

  int getSize();
};

int BinaryTree::getSizeRec(Node *node)
{
  if (node == nullptr)
    return 0;
  int leftNode = 1 + getSizeRec(node->left);
  int rightNode = 1 + getSizeRec(node->right);
  return leftNode + rightNode - 1;
}

int BinaryTree::getSize()
{
  return getSizeRec(this->root);
}

void printTree_PreOrder(Node *root)
{
  if (root != nullptr)
  {
    cout << root->data << " ";
    printTree_PreOrder(root->left);
    printTree_PreOrder(root->right);
  }
}

void printTree_InOrder(Node *root)
{
  if (root == nullptr)
    return;
  printTree_InOrder(root->left);
  cout << root->data << " ";
  printTree_InOrder(root->right);
}

int main()
{
  BinaryTree tree;
  // tree.root = new Node(4);
  // tree.root->left = new Node(2);
  // tree.root->right = new Node(7);
  // tree.root->left->left = new Node(1);
  // tree.root->left->right = new Node(3);
  // tree.root->right->right = new Node(11);

  tree.root = new Node(2);
  tree.root->left = new Node(1);
  tree.root->right = new Node(4);
  tree.root->right->left = new Node(3);

  // tree.root = new Node(10);
  // tree.root->left = new Node(7);
  // tree.root->right = new Node(18);
  // tree.root->right->left = new Node(15);
  // tree.root->right->left->left = new Node(13);

  printTree_PreOrder(tree.root);
  cout << "\nSize: " << tree.getSize() << endl;
  return 0;
}