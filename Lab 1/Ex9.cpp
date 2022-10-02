#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMaxOrMin(vector<int> &nums, bool findMax)
{
    // findMax is true if find max, otherwise false
    int res = findMax ? INT_MIN : INT_MAX;
    for (int x : nums)
    {
        if (findMax)
        {
            if (res < x)
                res = x;
        }
        else
        {

            if (res > x)
                res = x;
        }
    }
    return res;
}

int minimumAmplitude(vector<int> &nums, int k)
{
    // STUDENT ANSWER
    int res = INT_MAX;
    int size = nums.size();
    for (int i = 0; i <= size - k; i++)
    {
        vector<int> newNums = nums;
        newNums.erase(newNums.begin() + i, newNums.begin() + i + k);
        int maxValue = findMaxOrMin(newNums, true);
        int minValue = findMaxOrMin(newNums, false);
        int diff = maxValue - minValue;
        if (res > diff)
            res = diff;
    }
    return res;
}

int main()
{
    vector<int> nums{9, 6, 2, 1, 10, 7};
    int k = 2;
    cout << minimumAmplitude(nums, k);
    return 0;
}