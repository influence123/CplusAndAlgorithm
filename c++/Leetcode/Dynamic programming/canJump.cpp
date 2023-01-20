#include <iostream>
#include <vector>
//动态转移方程：jumpstep[i] = max(nums[i],jumpstep[i-1]-1);
//动态规划停止条件：i+jumpstep[i]>=nums.size()-1
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxstep = nums[0];
        int tempstep = 0;
        for(int i = 1; i < nums.size()-1; i++)
        {
            maxstep = max(nums[i],tempstep-1);
            if(maxstep==0)
            {
                return false;
            }
            tempstep = maxstep;
        }
        return true;
    }
};

int main()
{
    vector<int> v;
    v = {2,3,1,1,4};
    Solution S;
    S.canJump(v);
    return 0;
}