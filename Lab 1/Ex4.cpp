#include <iostream>

using namespace std;

int findMax(int *arr, int length)
{
    /*
     * STUDENT ANSWER
     */
    if (length == 1)
        return arr[0];
    int value = findMax(arr + 1, length - 1);
    return value > arr[0] ? value : arr[0];
}

int main()
{
    int *arr = new int[5]{1, 55, 2117, 505, 10};
    cout << findMax(arr, 5);
    return 0;
}