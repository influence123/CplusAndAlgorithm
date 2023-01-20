#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int i = 0;
        int j = nums.size()-1;
        vector<int> ans(nums.size());
        int k = ans.size()-1;
        while(k>=0)
        {
            if(nums[i]*nums[i]>=nums[j]*nums[j])
            {
                ans[k] = nums[i]*nums[i];
                i++;
            }
            else
            {
                ans[k] = nums[j]*nums[j];
                j--;
            }
            k--;
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> v;
    v = {-7,-3,2,3,11};
    S.sortedSquares(v);
    return 0;
}