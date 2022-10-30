#include <iostream>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

class BTNode
{
public:
  int val;
  BTNode *left;
  BTNode *right;
  BTNode()
  {
    this->left = this->right = NULL;
  }
  BTNode(int val)
  {
    this->val = val;
    this->left = this->right = NULL;
  }
  BTNode(int val, BTNode *&left, BTNode *&right)
  {
    this->val = val;
    this->left = left;
    this->right = right;
  }
};

int secondDeepest(BTNode *root)
{
  // Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the depth of the second deepest leaf/leaves of the tree (if there is no leaf satisfying, return -1).
  // In a binary tree, the second deepest leaf's/leaves' depth is smaller than the deepest leaf/leaves's depth and higher than the others' depth.
  if (root == NULL)
    return -1;
  int left = secondDeepest(root->left);
  int right = secondDeepest(root->right);
  if (left == -1 && right == -1)
    return 0;
  if (left == -1)
    return right + 1;
  if (right == -1)
    return left + 1;
  return min(left, right) + 1;
}

int main()
{
}