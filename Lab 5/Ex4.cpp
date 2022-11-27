#include <iostream>

using namespace std;

template <class T>
class Heap
{
protected:
  T *elements;
  int capacity;
  int count;

public:
  Heap()
  {
    this->capacity = 10;
    this->count = 0;
    this->elements = new T[capacity];
  }
  ~Heap()
  {
    delete[] elements;
  }
  void push(T item);
  void printHeap()
  {
    cout << "Max Heap [ ";
    for (int i = 0; i < count; i++)
      cout << elements[i] << " ";
    cout << "]";
  }

private:
  void ensureCapacity(int minCapacity);
  void reheapUp(int position);
};

template <class T>
void Heap<T>::push(T item)
{
  ensureCapacity(count + 1);
  elements[count] = item;
  reheapUp(count);
  count++;
}

template <class T>
void Heap<T>::ensureCapacity(int minCapacity)
{
  if (minCapacity > capacity)
  {
    T *newElements = new T[minCapacity];
    for (int i = 0; i < count; i++)
      newElements[i] = elements[i];
    delete[] elements;
    elements = newElements;
    capacity = minCapacity;
  }
}

template <class T>
void Heap<T>::reheapUp(int position)
{
  int parent = (position - 1) / 2;
  T temp = elements[position];
  while (position > 0 && temp > elements[parent])
  {
    elements[position] = elements[parent];
    position = parent;
    parent = (position - 1) / 2;
  }
  elements[position] = temp;
}

int main()
{
  Heap<int> maxHeap;
  for (int i = 0; i < 5; i++)
    maxHeap.push(i);
  maxHeap.printHeap();
}