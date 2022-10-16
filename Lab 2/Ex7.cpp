#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int sumOfMinSubarray(vector<int> &nums)
{
  int sum = 0;
  stack<int> s;
  for (int i = 0; i < nums.size(); i++)
  {
    while (!s.empty() && nums[s.top()] > nums[i])
    {
      int j = s.top();
      s.pop();
      int k = s.empty() ? -1 : s.top();
      sum += nums[j] * (i - j) * (j - k);
      sum %= 10000;
    }
    s.push(i);
  }
  while (!s.empty())
  {
    int j = s.top();
    s.pop();
    int k = s.empty() ? -1 : s.top();
    sum += nums[j] * (nums.size() - j) * (j - k);
    sum %= 10000;
  }
  return sum;
}

int main()
{
  vector<int> arr = {1, 2, 4, 3};
  cout << sumOfMinSubarray(arr) << endl;
  return 0;
}