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

int longestPathSum(BTNode *root)
{
  // Where root is the root node of given binary tree (this tree has between 1 and 100000 elements). This function returns the sum of the largest path from the root node to a leaf node. If there are more than one equally long paths, return the larger sum.
  if (root == NULL)
    return 0;
  int left = longestPathSum(root->left);
  int right = longestPathSum(root->right);
  return root->val + max(left, right);
}

int main()
{
}