#include <iostream>
#include <sstream>
#include <type_traits>

using namespace std;

template <class T>
class Sorting
{
private:
  static T *Partition(T *start, T *end)
  {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    // You can't use the function swap to swap two elements.
    T pivot = *start;
    T *i = start + 1;
    T *j = end - 1;
    while (i <= j)
    {
      while (i <= j && *i <= pivot)
        i++;
      while (i <= j && *j > pivot)
        j--;
      if (i < j)
      {
        T temp = *i;
        *i = *j;
        *j = temp;
      }
    }
    T temp = *start;
    *start = *j;
    *j = temp;
    return j;
  }

public:
  static void QuickSort(T *start, T *end)
  {
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    // TODO
    if (start < end)
    {
      T *pivot = Partition(start, end);
      cout << pivot - start << " ";
      QuickSort(start, pivot - 1);
      QuickSort(pivot + 1, end);
    }
  }
};

int main()
{
  int array[] = {3, 5, 7, 10, 12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19};
  cout << "Index of pivots: ";
  Sorting<int>::QuickSort(&array[0], &array[19]);
  cout << "\n";
  cout << "Array after sorting: ";
  for (int i : array)
    cout << i << " ";
}