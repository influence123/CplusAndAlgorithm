#include <iostream>
#include <vector>
//动态规划方程为：maxp[i] = max(maxp[i-2]+maxp,maxp[i-1])
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> maxp(nums.size());
        if(nums.size()==1)
        {
            return nums[0];
        }
        else if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        else 
        {
            maxp[0] = nums[0];
            maxp[1] = max(nums[0],nums[1]);
            for(int i = 2; i < nums.size(); i++)
            {
                maxp[i] = max(maxp[i-2]+nums[i],maxp[i-1]);
            }
            return maxp.back();
        }
    }
};

int main()
{
    Solution S;
    vector<int> v;
    v = {1,2,3,1};
    S.rob(v);
    return 0;
}