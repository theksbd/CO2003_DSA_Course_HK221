#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class T>
class DLinkedList
{
public:
  class Node; // Forward declaration
protected:
  Node *head;
  Node *tail;
  int count;

public:
  DLinkedList();
  ~DLinkedList();
  void add(const T &e);
  void add(int index, const T &e);
  int size();
  bool empty();
  T get(int index);
  void set(int index, const T &e);
  int indexOf(const T &item);
  bool contains(const T &item);
  T removeAt(int index);
  bool removeItem(const T &item);
  void clear();

public:
  class Node
  {
  private:
    T data;
    Node *next;
    Node *previous;
    friend class DLinkedList<T>;

  public:
    Node()
    {
      this->previous = NULL;
      this->next = NULL;
    }

    Node(const T &data)
    {
      this->data = data;
      this->previous = NULL;
      this->next = NULL;
    }
  };
};

template <class T>
void DLinkedList<T>::add(const T &e)
{
  /* Insert an element into the end of the list. */
  Node *newNode = new Node(e);
  if (this->head == nullptr)
    this->head = newNode;
  else
  {
    this->tail->next = newNode;
    newNode->previous = this->tail;
  }
  this->tail = newNode;
  this->count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
  /* Insert an element into the list at given index. */
  if (index < 0 || index > this->count)
    throw out_of_range("The index is out of range!");
  Node *newNode = new Node(e);
  if (index == 0)
  {
    if (this->head == nullptr)
      this->head = this->tail = newNode;
    else
    {
      this->head->previous = newNode;
      newNode->next = this->head;
      this->head = newNode;
    }
  }
  else if (index == this->count)
  {
    this->tail->next = newNode;
    newNode->previous = this->tail;
    this->tail = newNode;
  }
  else
  {
    Node *prevNode = this->head;
    for (int i = 0; i < index - 1; i++)
      prevNode = prevNode->next;
    newNode->previous = prevNode;
    newNode->next = prevNode->next;
    prevNode->next->previous = newNode;
    prevNode->next = newNode;
  }
  this->count++;
}

template <class T>
int DLinkedList<T>::size()
{
  /* Return the length (size) of list */
  return this->count;
}

template <class T>
T DLinkedList<T>::get(int index)
{
  /* Give the data of the element at given index in the list. */
  if (index < 0 || index >= this->count)
    throw out_of_range("The index is out of range!");
  if (index == 0)
    return this->head->data;
  if (index == this->count - 1)
    return this->tail->data;
  Node *currentNode = this->head->next;
  for (int i = 1; i < index; i++)
    currentNode = currentNode->next;
  return currentNode->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T &e)
{
  /* Assign new value for element at given index in the list */
  if (index < 0 || index >= this->count)
    throw out_of_range("The index is out of range!");
  if (index == 0)
    this->head->data = e;
  if (index == this->count - 1)
    this->tail->data = e;
  Node *currentNode = this->head->next;
  for (int i = 1; i < index; i++)
    currentNode = currentNode->next;
  currentNode->data = e;
}

template <class T>
bool DLinkedList<T>::empty()
{
  /* Check if the list is empty or not. */
  return (this->count == 0);
}

template <class T>
int DLinkedList<T>::indexOf(const T &item)
{
  /* Return the first index whether item appears in list, otherwise return -1 */
  if (this->count == 0)
    return -1;
  if (this->head->data == item)
    return 0;
  Node *currentNode = this->head->next;
  for (int i = 1; i < this->count; i++)
  {
    if (currentNode->data == item)
      return i;
    currentNode = currentNode->next;
  }
  return -1;
}

template <class T>
bool DLinkedList<T>::contains(const T &item)
{
  /* Check if item appears in the list */
  return (this->indexOf(item) != -1);
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
  /* Remove element at index and return removed value */
  if (index < 0 || index >= this->count)
    throw out_of_range("The index is out of range!");
  Node *deletedNode = this->head;
  if (index == 0)
  {
    if (this->count == 1)
      this->head = this->tail = nullptr;
    else
    {
      this->head = this->head->next;
      this->head->previous = nullptr;
    }
  }
  else if (index == this->count - 1)
  {
    deletedNode = this->tail;
    this->tail = this->tail->previous;
    this->tail->next = nullptr;
  }
  else
  {
    Node *prevNode = this->head;
    deletedNode = deletedNode->next;
    for (int i = 1; i < index; i++)
    {
      prevNode = prevNode->next;
      deletedNode = deletedNode->next;
    }
    prevNode->next = deletedNode->next;
    deletedNode->next->previous = prevNode;
  }
  int value = deletedNode->data;
  delete deletedNode;
  this->count--;
  return value;
}

template <class T>
bool DLinkedList<T>::removeItem(const T &item)
{
  /* Remove the first appearance of item in list and return true, otherwise return false */
  int index = this->indexOf(item);
  if (index == -1)
    return false;
  this->removeAt(index);
  return true;
}

template <class T>
void DLinkedList<T>::clear()
{
  /* Remove all elements in list */
  while (this->head != nullptr)
  {
    Node *deletedNode = this->head;
    this->head = this->head->next;
    delete deletedNode;
    this->count--;
  }
  this->tail = nullptr;
}

int main()
{

  return 0;
}