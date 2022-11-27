#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <utility>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <algorithm>

using namespace std;

// Given an integer array nums. In each operation, two numbers are removed from array, and their sum is pushed back to the array. The cost of the operation is the sum of the two removed numbers.

// Where nums is the mentioned array (the number of elements is between 1 and 100000). This function returns the minimum sum of cost after repeating the operation until the array is reduced to one element.
int reduceSum(vector<int> &nums)
{
  // STUDENT ANSWER
  int res = 0;
  sort(nums.begin(), nums.end());
  while (nums.size() > 1)
  {
    int sum = nums[0] + nums[1];
    res += sum;
    nums.erase(nums.begin(), nums.begin() + 2);
    int indexToInsert = lower_bound(nums.begin(), nums.end(), sum) - nums.begin();
    nums.insert(nums.begin() + indexToInsert, sum);
  }
  return res;
}

int main()
{
  vector<int> nums{1, 2, 3, 4};
  cout << reduceSum(nums);
}