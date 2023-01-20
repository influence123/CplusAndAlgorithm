#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int left = 0;
        int right = 0;
        for(; right< nums.size();right++)
        {
            if(nums[right]!=0)
            {
                swap(nums[left],nums[right]);
                left++;
            }
        }
    }
};

int main()
{
    Solution S;
    vector<int> v;
    v = {0,1,0,3,12};
    S.moveZeroes(v);
    return 0;
}