#include <iostream>

using namespace std;

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
  if (index < 0 || index >= numberOfElements)
    return;
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

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
  if (index >= numberOfElements)
    return;
  if (index > 0)
  {
    int parent = (index - 1) / 2;
    if (maxHeap[index] > maxHeap[parent])
    {
      swap(maxHeap[index], maxHeap[parent]);
      reheapUp(maxHeap, numberOfElements, parent);
    }
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int size = sizeof(arr) / sizeof(arr[0]);
  reheapDown(arr, size, 0);
  cout << "[ ";
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << "]";
}