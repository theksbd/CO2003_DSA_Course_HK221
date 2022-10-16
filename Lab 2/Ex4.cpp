#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *left;
  ListNode *right;
  ListNode(int x = 0, ListNode *l = nullptr, ListNode *r = nullptr) : val(x), left(l), right(r) {}
};

void insert(ListNode *&head, int x)
{
  if (head == nullptr)
  {
    head = new ListNode(x);
    return;
  }
  ListNode *current = head;
  while (current->right != nullptr)
    current = current->right;
  ListNode *newNode = new ListNode(x, current, nullptr);
  current->right = newNode;
}

void printList(ListNode *head)
{
  while (head != NULL)
  {
    cout << head->val << " ";
    head = head->right;
  }
  cout << '\n';
}

ListNode *reverse(ListNode *head, int a, int b)
{
  // To Do
  if (head == nullptr)
    return nullptr;
  ListNode *start = head;
  ListNode *end = head;
  ListNode *prev = nullptr;
  ListNode *next = nullptr;
  for (int i = 1; i < a; i++)
    start = start->right;
  for (int i = 1; i < b; i++)
    end = end->right;
  prev = start->left;
  next = end->right;
  ListNode *current = start;
  while (current != next)
  {
    ListNode *temp = current->right;
    current->right = current->left;
    current->left = temp;
    current = temp;
  }
  if (prev != nullptr)
    prev->right = end;
  else
    head = end;
  if (next != nullptr)
    next->left = start;
  start->right = next;

  return head;
}

int main()
{
  int a[] = {3, 4, 5, 6, 7};
  ListNode *head;
  for (int x : a)
    insert(head, x);
  printList(head);
  head = reverse(head, 2, 4);
  printList(head);
  return 0;
}