#include <iostream>
#include <vector>
// 动态转移方程为：maxstep = max(tempstep-1,nums[i])
// 终止条件为：maxstep+i>=nums.size()-1
// 跳跃步数计算为：每当取了nums[i],stepcount++
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int maxstep = 0;
        int tempstep = 0;
        int stepcount = -1;//设置为-1的原因为：从0开始循环，跳入nums[0]算一步
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxstep = max(tempstep - 1, nums[i]);
            if (tempstep - 1 <= nums[i])
            {
                stepcount++;
            }
            if (maxstep + i >= nums.size() - 1)
            {
                return ++stepcount;//设置stepcount自增的原因为：算得步数已经够跳跃到数组尾，但是还没跳出
            }
            tempstep = maxstep;
        }
        return 1;//返回1的原因为：当数组大小为2时，不能进入上述循环，但一定能到达
    }
};

int main()
{
    vector<int> v;
    v = {1, 2, 3};
    Solution S;
    S.jump(v);
    return 0;
}