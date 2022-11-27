#include <iostream>

using namespace std;

int interpolationSearch(int arr[], int left, int right, int x)
{
  if (x < arr[0])
    return -1;
  if (left == right - 1)
  {
    if (arr[left] != x && arr[right] != x)
      return -1;
  }
  if (left <= right)
  {
    int pos = left + (right - left) * (x - arr[left]) / (arr[right] - arr[left]);
    cout << "We traverse on index: " << pos << endl;
    if (x > arr[pos])
      return interpolationSearch(arr, pos + 1, right, x);
    else if (x < arr[pos])
      return interpolationSearch(arr, left, pos - 1, x);
    else
      return pos;
  }
  return -1;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -2, -3, -4, -9, 0, 99, 55};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 22;
  int result = interpolationSearch(arr, 0, n - 1, x);
  (result == -1) ? cout << "Element is not present in array"
                 : cout << "Element is present at index " << result;
}