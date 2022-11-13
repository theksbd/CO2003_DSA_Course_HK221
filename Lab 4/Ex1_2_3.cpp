#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
  LH = -1,
  EH = 0,
  RH = 1
};

void printNSpace(int n)
{
  for (int i = 0; i < n - 1; i++)
    cout << " ";
}

void printInteger(int &n)
{
  cout << n << " ";
}

template <class T>
class AVLTree
{
public:
  class Node;

private:
  Node *root;

protected:
  int getHeightRec(Node *node)
  {
    if (node == NULL)
      return 0;
    int lh = this->getHeightRec(node->pLeft);
    int rh = this->getHeightRec(node->pRight);
    return (lh > rh ? lh : rh) + 1;
  }

public:
  AVLTree() : root(nullptr) {}
  ~AVLTree() {}

  int getHeight()
  {
    return this->getHeightRec(this->root);
  }

  void printTreeStructure()
  {
    int height = this->getHeight();
    if (this->root == NULL)
    {
      cout << "NULL\n";
      return;
    }
    queue<Node *> q;
    q.push(root);
    Node *temp;
    int count = 0;
    int maxNode = 1;
    int level = 0;
    int space = pow(2, height);
    printNSpace(space / 2);
    while (!q.empty())
    {
      temp = q.front();
      q.pop();
      if (temp == NULL)
      {
        cout << " ";
        q.push(NULL);
        q.push(NULL);
      }
      else
      {
        cout << temp->data;
        q.push(temp->pLeft);
        q.push(temp->pRight);
      }
      printNSpace(space);
      count++;
      if (count == maxNode)
      {
        cout << endl;
        count = 0;
        maxNode *= 2;
        level++;
        space /= 2;
        printNSpace(space / 2);
      }
      if (level == height)
        return;
    }
  }

  Node *rotateLeft(Node *root)
  {
    Node *temp = root->pRight;
    root->pRight = temp->pLeft;
    temp->pLeft = root;

    if (root->pRight == NULL)
      root->balance = EH;
    else
      root->balance = LH;

    return temp;
  }

  Node *rotateRight(Node *root)
  {
    Node *temp = root->pLeft;
    root->pLeft = temp->pRight;
    temp->pRight = root;

    if (root->pLeft == NULL)
      root->balance = EH;
    else
      root->balance = RH;

    return temp;
  }

  Node *leftBalance(Node *root, bool &taller)
  {
    Node *leftTree = root->pLeft;
    // Case 1: LoL
    if (leftTree->balance == LH)
    {
      root = rotateRight(root);
      root->balance = EH;
      leftTree->balance = EH;
      taller = false;
    }
    // Case 2: RoL
    else
    {
      Node *rightTree = leftTree->pRight;
      if (rightTree->balance == LH)
      {
        root->balance = RH;
        leftTree->balance = EH;
      }
      else if (rightTree->balance == EH)
        leftTree->balance = EH;
      else
      {
        root->balance = EH;
        leftTree->balance = LH;
      }
      rightTree->balance = EH;
      root->pLeft = rotateLeft(leftTree);
      root = rotateRight(root);
      taller = false;
    }
    return root;
  }

  Node *rightBalance(Node *root, bool &taller)
  {
    Node *rightTree = root->pRight;
    // Case 1: RoR
    if (rightTree->balance == RH)
    {
      root = rotateLeft(root);
      root->balance = EH;
      rightTree->balance = EH;
      taller = false;
    }
    // Case 2: LoR
    else
    {
      Node *leftTree = rightTree->pLeft;
      if (leftTree->balance == RH)
      {
        root->balance = LH;
        rightTree->balance = EH;
      }
      else if (leftTree->balance == EH)
        rightTree->balance = EH;
      else
      {
        root->balance = EH;
        rightTree->balance = RH;
      }
      leftTree->balance = EH;
      root->pRight = rotateRight(rightTree);
      root = rotateLeft(root);
      taller = false;
    }
    return root;
  }

  Node *AVLinsert(Node *root, Node *newNode, bool &taller)
  {
    if (root == nullptr)
    {
      root = newNode;
      taller = true;
      return root;
    }
    if (newNode->data < root->data)
    {
      root->pLeft = AVLinsert(root->pLeft, newNode, taller);
      if (taller)
      {
        if (root->balance == LH)
          root = leftBalance(root, taller);
        else if (root->balance == EH)
          root->balance = LH;
        else
        {
          root->balance = EH;
          taller = false;
        }
      }
    }
    else
    {
      root->pRight = AVLinsert(root->pRight, newNode, taller);
      if (taller)
      {
        if (root->balance == LH)
        {
          root->balance = EH;
          taller = false;
        }
        else if (root->balance == EH)
          root->balance = RH;
        else
          root = rightBalance(root, taller);
      }
    }
    return root;
  }

  void insert(const T &value)
  {
    // TODO
    Node *newNode = new Node(value);
    bool taller = false;
    this->root = AVLinsert(this->root, newNode, taller);
  }

  void printInorderHelper(Node *root)
  {
    if (root == nullptr)
      return;
    printInorderHelper(root->pLeft);
    cout << root->data << " ";
    printInorderHelper(root->pRight);
  }

  void printInorder()
  {
    // TODO
    this->printInorderHelper(this->root);
  }

  bool search(const T &value)
  {
    // TODO
    if (this->root == nullptr)
      return false;
    Node *temp = this->root;
    while (temp)
    {
      if (temp->data == value)
        return true;
      else if (value < temp->data)
        temp = temp->pLeft;
      else
        temp = temp->pRight;
    }
    return false;
  }

  Node *deleteRightBalance(Node *root, bool &shorter)
  {
    if (root->balance == LH)
      root->balance = EH;
    else if (root->balance == EH)
    {
      root->balance = RH;
      shorter = false;
    }
    else
    {
      Node *rightTree = root->pRight;
      if (rightTree->balance == LH)
      {
        Node *leftTree = rightTree->pLeft;
        if (leftTree->balance == LH)
        {
          rightTree->balance = RH;
          root->balance = EH;
        }
        else if (leftTree->balance == EH)
        {
          root->balance = LH;
          rightTree->balance = EH;
        }
        else
        {
          root->balance = LH;
          rightTree->balance = EH;
        }
        leftTree->balance = EH;
        root->pRight = rotateRight(rightTree);
      }
      else
      {
        if (rightTree->balance == RH)
        {
          root->balance = EH;
          rightTree->balance = EH;
        }
        else
        {
          root->balance = RH;
          rightTree->balance = LH;
          shorter = false;
        }
        root = rotateLeft(root);
      }
    }
    return root;
  }

  Node *deleteLeftBalance(Node *root, bool &shorter)
  {
    if (root->balance == RH)
      root->balance = EH;
    else if (root->balance == EH)
    {
      root->balance = LH;
      shorter = false;
    }
    else
    {
      Node *leftTree = root->pLeft;
      if (leftTree->balance == RH)
      {
        Node *rightTree = leftTree->pRight;
        if (rightTree->balance == RH)
        {
          leftTree->balance = LH;
          root->balance = EH;
        }
        else if (rightTree->balance == EH)
        {
          root->balance = RH;
          leftTree->balance = EH;
        }
        else
        {
          root->balance = RH;
          leftTree->balance = EH;
        }
        rightTree->balance = EH;
        root->pLeft = rotateLeft(leftTree);
      }
      else
      {
        if (leftTree->balance == LH)
        {
          root->balance = EH;
          leftTree->balance = EH;
        }
        else
        {
          root->balance = LH;
          leftTree->balance = RH;
          shorter = false;
        }
        root = rotateRight(root);
      }
    }
    return root;
  }

  Node *AVLdelete(Node *root, T value, bool &shorter, bool &success)
  {
    if (root == nullptr)
    {
      shorter = success = false;
      return NULL;
    }
    if (value < root->data)
    {
      root->pLeft = AVLdelete(root->pLeft, value, shorter, success);
      if (shorter == true)
        root = deleteRightBalance(root, shorter);
    }
    else if (value > root->data)
    {
      root->pRight = AVLdelete(root->pRight, value, shorter, success);
      if (shorter == true)
        root = deleteLeftBalance(root, shorter);
    }
    else
    {
      Node *deleteNode = root;
      if (deleteNode->pRight == nullptr)
      {
        Node *newRoot = root->pLeft;
        success = true;
        shorter = true;
        delete deleteNode;
        return newRoot;
      }
      else if (deleteNode->pLeft == nullptr)
      {
        Node *newRoot = root->pRight;
        success = true;
        shorter = true;
        delete deleteNode;
        return newRoot;
      }
      else
      {
        Node *temp = root->pLeft;
        while (temp->pRight != nullptr)
          temp = temp->pRight;
        root->data = temp->data;
        root->pLeft = AVLdelete(root->pLeft, temp->data, shorter, success);
        if (shorter == true)
          root = deleteRightBalance(root, shorter);
      }
    }
    return root;
  }

  void remove(const T &value)
  {
    // TODO
    bool shorter = false, success = false;
    this->root = AVLdelete(this->root, value, shorter, success);
  }

  class Node
  {
  private:
    T data;
    Node *pLeft, *pRight;
    BalanceValue balance;
    friend class AVLTree<T>;

  public:
    Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
    ~Node() {}
  };
};

int main()
{
  AVLTree<int> avl;
  int arr[] = {10, 52, 98, 32, 68, 92, 40, 13, 42, 63};
  for (int i = 0; i < 10; i++)
  {
    avl.insert(arr[i]);
  }
  avl.printTreeStructure();
  cout << endl;
  cout << endl;
  cout << endl;
  // avl.printInorder();
  // cout << endl;
  // cout << endl;
  // cout << endl;
  // cout << avl.search(10);
  // cout << endl;
  // cout << endl;
  // cout << endl;
  avl.remove(10);
  avl.printTreeStructure();
  return 0;
}