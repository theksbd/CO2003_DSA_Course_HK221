#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

class SplayTree
{
  struct Node
  {
    int val;
    Node *pLeft;
    Node *pRight;
    Node *pParent;
    Node(int val = 0, Node *l = nullptr, Node *r = nullptr, Node *par = nullptr) : val(val), pLeft(l), pRight(r), pParent(par) {}
  };
  Node *root;

  // print the tree structure for local testing
  void printBinaryTree(string prefix, const Node *root, bool isLeft, bool hasRightSibling)
  {
    if (!root && isLeft && hasRightSibling)
    {
      cout << prefix << "├──\n";
    }
    if (!root)
      return;
    cout << prefix;
    if (isLeft && hasRightSibling)
      cout << "├──";
    else
      cout << "└──";
    cout << root->val << '\n';
    printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pLeft, true, root->pRight);
    printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pRight, false, root->pRight);
  }

  void printPreorder(Node *p)
  {
    if (!p)
    {
      return;
    }
    cout << p->val << ' ';
    printPreorder(p->pLeft);
    printPreorder(p->pRight);
  }

public:
  SplayTree()
  {
    root = nullptr;
  }
  ~SplayTree()
  {
    // Ignore deleting all nodes in the tree
  }

  void printBinaryTree()
  {
    printBinaryTree("", root, false, false);
  }

  void printPreorder()
  {
    printPreorder(root);
    cout << "\n";
  }

  // help function

  void Zig(Node *root)
  {
    Node *parentNode = root->pParent;

    if (parentNode->pLeft == root)
    {
      Node *rightTreeOfRoot = root->pRight;

      // rotate parent to right
      root->pRight = parentNode;
      parentNode->pLeft = rightTreeOfRoot;
      root->pParent = NULL;
      parentNode->pParent = root;

      if (rightTreeOfRoot != NULL)
        rightTreeOfRoot->pParent = parentNode;
    }
    else
    {
      Node *leftTreeOfRoot = root->pLeft;

      // rotate parent to left
      root->pLeft = parentNode;
      parentNode->pRight = leftTreeOfRoot;
      // update parent
      root->pParent = NULL;
      parentNode->pParent = root;

      if (leftTreeOfRoot != NULL)
        leftTreeOfRoot->pParent = parentNode;
    }
  }

  void Zig_Zig(Node *root)
  {
    Node *parentNode = root->pParent;
    Node *grandNode = parentNode->pParent;
    if (parentNode->pLeft == root)
    {
      Node *rightTreeOfRoot = root->pRight;
      Node *rightTreeOfParent = parentNode->pRight;

      // rotate parent and grand to right
      root->pRight = parentNode;
      parentNode->pLeft = rightTreeOfRoot;
      parentNode->pRight = grandNode;
      grandNode->pLeft = rightTreeOfParent;
      // update parent
      root->pParent = grandNode->pParent;
      parentNode->pParent = root;
      grandNode->pParent = parentNode;

      if (root->pParent != NULL) // update left or right pointer of (parent of grand) point to root
      {
        if (root->pParent->pLeft == grandNode)
          root->pParent->pLeft = root;
        else
          root->pParent->pRight = root;
      }

      if (rightTreeOfRoot != NULL)
        rightTreeOfRoot->pParent = parentNode;
      if (rightTreeOfParent != NULL)
        rightTreeOfParent->pParent = grandNode;
    }
    else
    {
      Node *leftTreeOfRoot = root->pLeft;
      Node *leftTreeOfParent = parentNode->pLeft;

      // rotate parent and grand to left
      root->pLeft = parentNode;
      parentNode->pRight = leftTreeOfRoot;
      parentNode->pLeft = grandNode;
      grandNode->pRight = leftTreeOfParent;
      // update parent
      root->pParent = grandNode->pParent;
      parentNode->pParent = root;
      grandNode->pParent = parentNode;

      if (root->pParent != NULL) // update left or right pointer of (parent of grand) point to root
      {
        if (root->pParent->pLeft == grandNode)
          root->pParent->pLeft = root;
        else
          root->pParent->pRight = root;
      }

      if (leftTreeOfParent != NULL)
        leftTreeOfParent->pParent = grandNode;
      if (leftTreeOfRoot != NULL)
        leftTreeOfRoot->pParent = parentNode;
    }
  }

  void Zig_Zag(Node *root)
  {
    Node *parentNode = root->pParent;
    Node *grandNode = parentNode->pParent;

    if (parentNode->pRight == root)
    {
      Node *leftTreeOfRoot = root->pLeft;
      Node *rightTreeOfRoot = root->pRight;

      // rotate parent to left then rotate grand to right
      root->pLeft = parentNode;
      root->pRight = grandNode;
      parentNode->pRight = leftTreeOfRoot;
      grandNode->pLeft = rightTreeOfRoot;
      // update parent
      root->pParent = grandNode->pParent;
      parentNode->pParent = root;
      grandNode->pParent = root;

      if (root->pParent != NULL)
      {
        if (root->pParent->pLeft == grandNode)
          root->pParent->pLeft = root;
        else
          root->pParent->pRight = root;
      }

      if (leftTreeOfRoot != NULL)
        leftTreeOfRoot->pParent = parentNode;
      if (rightTreeOfRoot != NULL)
        rightTreeOfRoot->pParent = grandNode;
    }
    else
    {
      Node *leftTreeOfRoot = root->pLeft;
      Node *rightTreeOfRoot = root->pRight;

      // rotate parent to right then rotate grand to left
      root->pLeft = grandNode;
      root->pRight = parentNode;
      parentNode->pLeft = rightTreeOfRoot;
      grandNode->pRight = leftTreeOfRoot;
      // update parent
      root->pParent = grandNode->pParent;
      parentNode->pParent = root;
      grandNode->pParent = root;

      if (root->pParent != NULL)
      {
        if (root->pParent->pLeft == grandNode)
          root->pParent->pLeft = root;
        else
          root->pParent->pRight = root;
      }

      if (leftTreeOfRoot != NULL)
        leftTreeOfRoot->pParent = grandNode;
      if (rightTreeOfRoot != NULL)
        rightTreeOfRoot->pParent = parentNode;
    }
  }

  void helpSplay(Node *root)
  {
    while (root->pParent != NULL)
    {
      Node *parentNode = root->pParent;
      Node *grandNode = parentNode->pParent;
      if (grandNode == NULL)
        Zig(root);
      else if (grandNode->pLeft == parentNode && parentNode->pLeft == root)
        Zig_Zig(root);
      else if (grandNode->pRight == parentNode && parentNode->pRight == root)
        Zig_Zig(root);
      else
        Zig_Zag(root);
    }
    this->root = root;
  }
  void splay(Node *p)
  {
    // TODO
    helpSplay(p);
  }

  void insert(int val)
  {
    // TODO
    if (this->root == NULL)
      this->root = new Node(val);
    else
    {
      Node *nNode = new Node(val);
      Node *walkNode = this->root;
      Node *parentNode = this->root;
      while (walkNode != NULL)
      {
        parentNode = walkNode;
        if (nNode->val < walkNode->val)
          walkNode = walkNode->pLeft;
        else
          walkNode = walkNode->pRight;
      }
      if (parentNode != NULL)
      {
        if (nNode->val < parentNode->val)
          parentNode->pLeft = nNode;
        else
          parentNode->pRight = nNode;
      }
      nNode->pParent = parentNode;
      splay(nNode);
    }
  }

  // Write your helper functions here

  bool search(int val)
  {
    // TODO
    Node *walkNode = this->root;
    Node *parentNode = this->root;
    while (walkNode != NULL)
    {
      parentNode = walkNode;
      if (val < walkNode->val)
        walkNode = walkNode->pLeft;
      else if (val > walkNode->val)
        walkNode = walkNode->pRight;
      else
      {
        splay(walkNode);
        return true;
      }
    }
    if (parentNode != NULL)
      splay(parentNode);
    return false;
  }

  // Write your helper functions here

  Node *remove(int val)
  {
    // TODO
    if (this->root == nullptr)
      return nullptr;
    Node *deleteNode = this->root;
    Node *parentNode = this->root;
    while (deleteNode != NULL)
    {
      parentNode = deleteNode;
      if (val < deleteNode->val)
        deleteNode = deleteNode->pLeft;
      else if (val > deleteNode->val)
        deleteNode = deleteNode->pRight;
      else
      {
        splay(deleteNode);
        Node *leftTree = deleteNode->pLeft;
        Node *rightTree = deleteNode->pRight;

        if (leftTree != NULL)
          leftTree->pParent = NULL;
        if (rightTree != NULL)
          rightTree->pParent = NULL;

        // find node that has largest key on left tree and choose it as new root
        if (leftTree != NULL)
        {
          while (leftTree->pRight != NULL)
          {
            leftTree = leftTree->pRight;
          }
          splay(leftTree);
          if (rightTree != NULL)
          {
            leftTree->pRight = rightTree;
            rightTree->pParent = leftTree;
          }
          this->root = leftTree;
        }
        else
        {
          if (rightTree != NULL)
            this->root = rightTree;
          else
            this->root = NULL;
        }
        return deleteNode;
      }
    }
    if (parentNode != NULL)
      splay(parentNode);
    return nullptr;
  }
};

// The methods splay, insert and search are already implemented.
// Implement the following method:
// Node* remove(int val): remove the first Node with value equal to val from the tree and return it.

// To perform remove operation on splay tree:
// 1. If root is NULL, return the root
// 2. Search for the first node containing the given value val and splay it. If val is present, the found node will become the root.
//    Else the last accessed leaf node becomes the root.
// 3. If new root's value is not equal to val, return NULL as val is not present.
// 4. Else the value val is present, we remove root from the tree by the following steps:
//     4.1 Split the tree into two tree: tree1 = root's left subtree and tree2 = root's right subtree
//     4.2 If tree1 is NULL, tree2 is the new root
//     4.3 Else, splay the leaf node with the largest value in tree1. tree1 will be a left skewed binary tree.
//     Make tree2 the right subtree of tree1. tree1 becomes the new root
//     4.4 Return the removed node.

// Constraints of the testcases:
// + number of operations <= 10^4
// + 1 <= val <= 10^5

int main()
{
  SplayTree tree;
  int query[] = {50, 70, 30, 80, 100, 90};
  for (int i = 0; i < 6; i++)
  {
    tree.insert(query[i]);
  }
  // print preorder traversal of the tree
  tree.printPreorder();
  // print structure of the tree
  tree.remove(80);
  tree.printPreorder();
}