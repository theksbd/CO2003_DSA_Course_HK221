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

int maximizeProduct(BTNode* root) {
  // Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the largest P which can be gotten after deleting an edge of this tree.
  // Split the binary tree into two subtrees by deleting an edge of it. Take the sum of each subtree, P is the product of these sums.
  if (root == NULL)
    return 0;
  int left = maximizeProduct(root->left);
  int right = maximizeProduct(root->right);
  return root->val * max(left, right);
}

int main()
{
}