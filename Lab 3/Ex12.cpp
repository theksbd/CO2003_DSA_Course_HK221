#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
class BinarySearchTree
{
public:
  class Node;

private:
  Node *root;

public:
  BinarySearchTree() : root(nullptr) {}
  ~BinarySearchTree()
  {
    // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
  }

  class Node
  {
  private:
    T value;
    Node *pLeft, *pRight;
    friend class BinarySearchTree<T>;

  public:
    Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
    ~Node() {}
  };
  Node *addRec(Node *root, T value)
  {
    if (root == NULL)
    {
      root = new Node(value);
      return root;
    }
    if (value < root->value)
    {
      root->pLeft = addRec(root->pLeft, value);
    }
    else if (value > root->value)
    {
      root->pRight = addRec(root->pRight, value);
    }
    return root;
  }
  void add(T value)
  {
    root = addRec(root, value);
  }
  // STUDENT ANSWER BEGIN
  // You can define other functions here to help you.

  T getMin()
  {
    // TODO: return the minimum values of nodes in the tree.
    if (!this->root)
      return 0;
    Node *current = this->root;
    while (current->pLeft)
    {
      current = current->pLeft;
    }
    return current->value;
  }

  T getMax()
  {
    // TODO: return the maximum values of nodes in the tree.
    if (!this->root)
      return 0;
    Node *current = this->root;
    while (current->pRight)
    {
      current = current->pRight;
    }
    return current->value;
  }

  // STUDENT ANSWER END
};