#include <iostream>
#include <vector>

using namespace std;

int equalSumIndex(vector<int> &nums)
{
    // STUDENT ANSWER
    int size = nums.size();
    int sumRight = 0;
    for (int x : nums)
        sumRight += x;
    int sumLeft = 0;
    for (int i = 0; i < size; i++)
    {
        sumRight -= nums[i];
        if (sumLeft == sumRight)
            return i;
        sumLeft += nums[i];
    }
    return -1;
}

int main()
{
    vector<int> nums{0, 10};
    cout << equalSumIndex(nums);
    return 0;
}