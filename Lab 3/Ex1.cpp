#include <iostream>

using namespace std;

template <class T>
class Sorting
{
public:
  /* Function to print an array */
  static void printArray(T *start, T *end)
  {
    long size = end - start + 1;
    for (int i = 0; i < size - 1; i++)
      cout << start[i] << ", ";
    cout << start[size - 1];
    cout << endl;
  }

  static void merge(T *left, T *middle, T *right)
  {
    /*TODO*/
    long sizeLeft = middle - left + 1;
    long sizeRight = right - middle;
    T *leftArray = new T[sizeLeft];
    T *rightArray = new T[sizeRight];
    for (int i = 0; i < sizeLeft; i++)
      leftArray[i] = left[i];
    for (int i = 0; i < sizeRight; i++)
      rightArray[i] = middle[i + 1];
    int indexLeft = 0, indexRight = 0, indexRes = 0;
    while (indexLeft < sizeLeft && indexRight < sizeRight)
    {
      if (leftArray[indexLeft] <= rightArray[indexRight])
        left[indexRes] = leftArray[indexLeft++];
      else
        left[indexRes] = rightArray[indexRight++];
      indexRes++;
    }
    while (indexLeft < sizeLeft)
      left[indexRes++] = leftArray[indexLeft++];
    while (indexRight < sizeRight)
      left[indexRes++] = rightArray[indexRight++];
    Sorting::printArray(left, right);
  }

  static void mergeSort(T *start, T *end)
  {
    /*TODO*/
    if (start < end)
    {
      T *middle = start + (end - start) / 2;
      mergeSort(start, middle);
      mergeSort(middle + 1, end);
      merge(start, middle, end);
    }
  }
};

int main()
{
  int arr[] = {0, 2, 4, 3, 1, 4};
  Sorting<int>::mergeSort(&arr[0], &arr[5]);
  return 0;
}