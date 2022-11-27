#include <iostream>
#include <vector>
#include <map>

using namespace std;

int pairMatching(vector<int> &nums, int target)
{
  // There are n people, each person has a number between 1 and 100000 (1 ≤ n ≤ 100000). Given a number target. Two people can be matched as a perfect pair if the sum of numbers they have is equal to target. A person can be matched no more than 1 time.
  // Where nums is the list of numbers of n people, target is the given number. This function returns the number of perfect pairs can be found from the list.
  // Example:
  // The list of numbers is {1, 3, 5, 3, 7} and target = 6. Therefore, the number of perfect pairs can be found from the list is 2 (pair (1, 5) and pair (3, 3)).
  // After a pair is picked, remove them from the list.
  // TODO
  int count = 0;
  map<int, int> m;
  for (int i = 0; i < int(nums.size()); i++)
  {
    m[nums[i]]++;
  }
  for (int i = 0; i < int(nums.size()); i++)
  {
    if (m[nums[i]] > 0)
    {
      if (m[target - nums[i]] > 0)
      {
        count++;
        m[nums[i]]--;
        m[target - nums[i]]--;
      }
    }
  }
  return count;
}

int main()
{
  // vector<int> items{1, 3, 5, 3, 7};
  vector<int> items{4, 4, 2, 1, 2};
  int target = 6;
  cout << pairMatching(items, target);
}