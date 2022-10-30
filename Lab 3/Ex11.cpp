#include <iostream>

using namespace std;

class BSTNode
{
public:
  int val;
  BSTNode *left;
  BSTNode *right;
  BSTNode()
  {
    this->left = this->right = nullptr;
  }
  BSTNode(int val)
  {
    this->val = val;
    this->left = this->right = nullptr;
  }
  BSTNode(int val, BSTNode *&left, BSTNode *&right)
  {
    this->val = val;
    this->left = left;
    this->right = right;
  }
};

BSTNode *subtreeWithRange(BSTNode *root, int lo, int hi)
{
  // Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). This function returns the binary search tree after deleting all nodes whose values are outside the range [lo, hi] (inclusive).
  // STUDENT ANSWER
  if (root == nullptr)
    return nullptr;
  if (root->val < lo)
    return subtreeWithRange(root->right, lo, hi);
  if (root->val > hi)
    return subtreeWithRange(root->left, lo, hi);
  root->left = subtreeWithRange(root->left, lo, hi);
  root->right = subtreeWithRange(root->right, lo, hi);
  return root;
}

void insertBST(BSTNode *&root, int val)
{
  if (root == nullptr)
  {
    root = new BSTNode(val);
    return;
  }
  BSTNode *current = root;
  BSTNode *parent = root;
  while (current != nullptr)
  {
    parent = current;
    if (val <= current->val)
      current = current->left;
    else if (val > current->val)
      current = current->right;
  }
  if (val <= parent->val)
    parent->left = new BSTNode(val);
  else
    parent->right = new BSTNode(val);
}

void printTree_PreOrder(BSTNode *root)
{
  if (root != nullptr)
  {
    cout << root->val << " ";
    printTree_PreOrder(root->left);
    printTree_PreOrder(root->right);
  }
}

void printTree_InOrder(BSTNode *root)
{
  if (root == nullptr)
    return;
  printTree_InOrder(root->left);
  cout << root->val << " ";
  printTree_InOrder(root->right);
}

int main()
{
  BSTNode *root1 = nullptr;
  insertBST(root1, 4);
  insertBST(root1, 2);
  insertBST(root1, 7);
  insertBST(root1, 3);
  insertBST(root1, 11);

  // TreeNode *root2 = nullptr;
  // insertBST(root2, 2);
  // insertBST(root2, 1);
  // insertBST(root2, 4);
  // insertBST(root2, 3);

  cout << subtreeWithRange(root1, 3, 7) << endl;

  return 0;
}