#include <iostream>
#include <queue>

using namespace std;

template <class T>
class Sorting
{
public:
  /* Function to print an array */
  static void printArray(T *start, T *end)
  {
    long size = end - start;
    for (int i = 0; i < size - 1; i++)
      cout << start[i] << ", ";
    cout << start[size - 1];
    cout << endl;
  }

  // Helping functions go here
  static void reheapDown(int maxHeap[], int numberOfElements, int index)
  {
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;
    int largeChild = index;
    if (leftChild <= numberOfElements - 1)
    {
      if (rightChild <= numberOfElements - 1 && maxHeap[rightChild] > maxHeap[leftChild])
        largeChild = rightChild;
      else
        largeChild = leftChild;
      if (maxHeap[largeChild] > maxHeap[index])
      {
        swap(maxHeap[largeChild], maxHeap[index]);
        reheapDown(maxHeap, numberOfElements, largeChild);
      }
    }
  }

  static void heapSort(T *start, T *end)
  {
    // TODO
    long size = end - start;
    for (int i = size / 2 - 1; i >= 0; i--)
      reheapDown(start, size, i);
    for (int i = size - 1; i >= 0; i--)
    {
      swap(start[0], start[i]);
      reheapDown(start, i, 0);
    }
    Sorting<T>::printArray(start, end);
  }
};

int main()
{
  int arr[4] = {4, 2, 9, 1};
  Sorting<int>::heapSort(&arr[0], &arr[4]);
}