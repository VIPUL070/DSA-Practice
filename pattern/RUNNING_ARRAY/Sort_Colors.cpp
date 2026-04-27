#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    int s = 0;
    int mid = 0;
    int e = nums.size() - 1;

    while (mid <= e)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[s]);
            mid++;
            s++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[e]);
            e--;
        }
    }
}