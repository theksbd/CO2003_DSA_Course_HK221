// success
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
};

// Method splay and insert are already implemented
// You have to implement the following method:

// bool search(int val): search for the value val in the tree.
// The search operation in splay tree do the same thing as BST search.
// In addition, it also splays the node containing the value to the root.
// +  If the search is successful, the node that is found will become the new root and the function return true.
// +  Else, the last accessed node will be splayed and become the new root and the function return false.

// Constraints of the testcases:
// +    number of operation <= 10^4
// +    1 <= val <= 10^5

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
  // tree.printBinaryTree();
  cout << tree.search(85) << endl;
  tree.printPreorder();
}