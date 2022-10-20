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

class BinarySearchTree
{
public:
  Node *root;
  int size;

protected:
  bool addRec(Node *&, const int &);
  bool removeRec(Node *&, const int &);

public:
  BinarySearchTree()
  {
    this->root = NULL;
    this->size = 0;
  }

  bool add(const int &value);
  bool remove(const int &value);
};

bool BinarySearchTree::addRec(Node *&node, const int &value)
{
  return true;
}

bool BinarySearchTree::add(const int &value)
{
  if (this->root == nullptr)
  {
    this->root = new Node(value);
  }
  else
  {
    Node *current = this->root;
    Node *parent = this->root;
    while (current != nullptr)
    {
      parent = current;
      if (value < current->data)
        current = current->left;
      else
        current = current->right;
    }
    if (value < parent->data)
      parent->left = new Node(value);
    else
      parent->right = new Node(value);
  }
  return true;
}

bool BinarySearchTree::removeRec(Node *&node, const int &value)
{
  if (node == nullptr)
    return false;
  if (value < node->data)
    return this->removeRec(node->left, value);
  else if (value > node->data)
    return this->removeRec(node->right, value);
  else
  {
    if (node->left == nullptr)
    {
      Node *dltNode = node;
      node = node->right;
      delete dltNode;
      return true;
    }
    else if (node->right == nullptr)
    {
      Node *dltNode = node;
      node = node->left;
      delete dltNode;
      return true;
    }
    else
    {
      Node *dltNode = node->left;
      while (dltNode->right)
      {
        dltNode = dltNode->right;
      }
      node->data = dltNode->data;
      return this->removeRec(node->left, dltNode->data);
    }
  }
}

bool BinarySearchTree::remove(const int &value)
{
  return this->removeRec(this->root, value);
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
  BinarySearchTree tree;
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
  cout << "\nSearch: " << tree.add(3) << endl;
  return 0;
}