#include <iostream>
#include <vector>
//动态转移方程：maxp[i] = max(maxp[i-2]+nums[i],maxp[i-1])
//此时边界除了maxp[0]和maxp[1]之外还有maxp[nums.size()-1]
//考虑计算两次，分别从[0,n-2]和[1,n-1]计算动态规划，再取最大值，即可排除头尾相连的情况
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> maxp1(nums.size()-1);
        vector<int> maxp2(nums.size());
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
            maxp1[0] = nums[0];
            maxp1[1] = max(nums[0],nums[1]);
            for(int i = 2; i < nums.size()-1; i++)
            {
                maxp1[i] = max(maxp1[i-2]+nums[i],maxp1[i-1]);
            }
            maxp2[0] = 0;
            maxp2[1] = nums[1];
            maxp2[2] = max(nums[1],nums[2]);
            for(int i = 3; i < nums.size(); i++)
            {
                maxp2[i] = max(maxp2[i-2]+nums[i],maxp2[i-1]);
            }
            return max(maxp1.back(),maxp2.back());
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