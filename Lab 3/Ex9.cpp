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

void help(BSTNode *root, vector<int> &v)
{
  // take all nodes in Inorder traversal
  if (root != nullptr)
  {
    help(root->left, v);
    v.push_back(root->val);
    help(root->right, v);
  }
}
bool findTarget(BSTNode *root, int k)
{
  if (!root)
    return false;
  if (!root->left && !root->right)
    return false;
  vector<int> v;
  help(root, v);

  int low = 0, high = v.size() - 1;
  while (low < high)
  {
    int sum = v[low] + v[high];
    if (sum > k)
      high--;
    else if (sum < k)
      low++;
    else
      return true;
  }
  return false;
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
  // insertBST(root1, 4);
  // insertBST(root1, 2);
  // insertBST(root1, 7);
  // insertBST(root1, 3);
  // insertBST(root1, 11);

  // TreeNode *root2 = nullptr;
  // insertBST(root2, 2);
  // insertBST(root2, 1);
  // insertBST(root2, 4);
  // insertBST(root2, 3);

  cout << findTarget(root1, 18) << endl;
  return 0;
}