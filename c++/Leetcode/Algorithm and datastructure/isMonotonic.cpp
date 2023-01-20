#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool flag;
        if(nums.size()==1)
        {
            return true;
        }
        // if (nums[0] >= nums[1])      不能这样分条件的原因为：有可能数组前几个都相等，但是无法判断前多少个
        // {
        //     flag = false;
        // }
        // else if (nums[0] <= nums[1])
        // {
        //     flag = true;
        // }
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            else if(nums[i]>nums[i-1])
            {
                flag = true;
                break;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] < nums[i - 1])
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] > nums[i - 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}