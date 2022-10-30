#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int _val = 0, ListNode *_next = nullptr) : val(_val), next(_next) {}
};

// Hint: You should complete the function mergeLists first and validate it using our first testcase example

ListNode *mergeLists(ListNode *a, ListNode *b)
{
  // Merge two sorted lists
  // You must use the nodes in the original list and must not modify ListNode's val attribute.
  ListNode *res = new ListNode();
  ListNode *head = res;
  while (a != nullptr && b != nullptr)
  {
    if (a->val <= b->val)
    {
      res->next = a;
      a = a->next;
    }
    else
    {
      res->next = b;
      b = b->next;
    }
    res = res->next;
  }
  if (a != nullptr)
    res->next = a;
  else
    res->next = b;
  return head->next;
}

ListNode *mergeSortList(ListNode *head)
{
  // Sort an unsorted list given its head pointer
  if (head == nullptr || head->next == nullptr)
    return head;
  ListNode *slow = head, *fast = head->next;
  while (fast != nullptr && fast->next != nullptr)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *mid = slow->next;
  slow->next = nullptr;
  ListNode *left = mergeSortList(head);
  ListNode *right = mergeSortList(mid);
  return mergeLists(left, right);
}

int main()
{
  ListNode *head = new ListNode(5, new ListNode(7, new ListNode(3, new ListNode(2, new ListNode(1, new ListNode(4))))));
  ListNode *sortedHead = mergeSortList(head);
  while (sortedHead != nullptr)
  {
    cout << sortedHead->val << " ";
    sortedHead = sortedHead->next;
  }
  return 0;
}