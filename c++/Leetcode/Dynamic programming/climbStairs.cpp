#include <iostream>
#define N 50

using namespace std;

class Solution 
{
public:
    int climbStairs(int n) 
    {
        int dp[N];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i<=n;i++)
        {
            dp[i] = dp[i-1]+dp[i-2];//动态规划方程
        }
        return dp[n];
    }
};

int main()
{
    Solution S;
    cout<<S.climbStairs(2)<<endl;
    return 0;
}