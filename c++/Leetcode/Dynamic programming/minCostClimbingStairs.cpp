#include <iostream>
#include <vector>
//动态规划方程：mincost（i） = min（mincost（i-2）+cost[i-2]，mincost（i-1）+cost[i-1]）
using namespace std;

class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> mincost(cost.size());
        for(int i = 2;i<cost.size();i++)
        {
            mincost[i] = min(mincost[i-2]+cost[i-2],mincost[i-1]+cost[i-1]);
        }
        return min(mincost.back()+cost[mincost.size()-1],mincost[mincost.size()-2]+cost[mincost.size()-2]);//mincost[i]表示的是到达第i阶梯需要的最少花费，到达楼梯顶，需要i-1和i在做一次取min
    }
};

int main()
{
    return 0;
}