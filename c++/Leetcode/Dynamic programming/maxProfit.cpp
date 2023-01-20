#include <iostream>
#include <vector>

// 动态规划方程：maxProfit（i） = max（maxProfit（i-1），max（for 0：i {prices[j]-prices[i]}）;

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> maxp(prices.size());
        int maxptemp = 0;
        int minprice = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            if(prices[i]<minprice)
            {
                minprice = prices[i];
            }
            if (prices[i] <= prices[i - 1])
            {
                maxp[i] = maxp[i-1];
            }
            else
            {
                // for (int j = 0; j < i; j++)求第i天的利润不需要循环前i-1天，只需要记录前i-1天的最小值
                // {
                //     if (prices[i] - prices[j] > maxptemp)
                //     {
                //         maxptemp = prices[i] - prices[j];
                //     }
                // }
                maxptemp = prices[i]-minprice;
                maxp[i] = max(maxp[i-1],maxptemp);
            }
        }
        return maxp.back();
    }
};

int main()
{
    Solution S;
    vector<int> prices;
    prices = {7, 1, 5, 3, 6, 4};
    S.maxProfit(prices);
    return 0;
}