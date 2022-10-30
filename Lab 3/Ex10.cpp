#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

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

void help(BSTNode *root, int &res)
{
  if (!root)
    return;
  bool onlyLeft = root->left && !root->right;
  bool onlyRight = !root->left && root->right;
  if (onlyLeft || onlyRight)
    res++;
  help(root->left, res);
  help(root->right, res);
}

int singleChild(BSTNode *root)
{
  // STUDENT ANSWER
  if (!root)
    return 0;
  if (!root->left && !root->right)
    return 0;
  int res = 0;
  help(root, res);
  return res;
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

  cout << singleChild(root1) << endl;
  return 0;
}