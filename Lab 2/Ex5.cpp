#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreater(vector<int> &arr)
{
  vector<int> res;
  for (unsigned int i = 0; i < arr.size() - 1; i++)
  {
    for (unsigned int j = i + 1; j < arr.size(); j++)
    {
      if (arr[j] > arr[i])
      {
        res.push_back(arr[j]);
        break;
      }
      if (j == arr.size() - 1)
        res.push_back(-1);
    }
  }
  res.push_back(-1);
  return res;
}

int main()
{
  vector<int> arr = {15, 1, 4, 10};
  for (int x : nextGreater(arr))
    cout << x << " ";
  return 0;
}