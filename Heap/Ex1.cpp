#include <iostream>

using namespace std;

int buildHeap(int a[], int n)
{
  int swaps = 0;
  for (int i = 1; i < n; ++i)
  {
    int child = i;
    while (child > 0)
    {
      int parent = (child - 1) / 2;
      if (a[parent] >= a[child])
        break;
      swap(a[parent], a[child]);
      swaps++;
      child = parent;
    }
  }
  return swaps;
}

int main()
{
  int a[] = {21, 19, 99, 89, 40, 77, 88, 69, 9, 87, 32, 61, 18, 36, 30};
  // int a[] = {73, 79, 47, 93, 65, 96, 44, 80, 85, 49, 37, 14, 38, 84, 22};
  int n = sizeof(a) / sizeof(int);
  cout << buildHeap(a, n) << endl;
  return 0;
}