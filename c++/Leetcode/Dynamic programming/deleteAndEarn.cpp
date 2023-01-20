#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
// 动态转移方程：xp[i] = max((maxp[i - 2] + sumnum[i]*i), maxp[i - 1]);
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        // map<int,int> hash;
        // for(int i = 0; i < nums.size();i++)//构建hash表
        // {
        //     if(hash.find(nums[i])!=hash.end())
        //     {
        //         hash.find(nums[i])->second++;
        //     }
        //     else
        //     {
        //         hash.insert(pair<int,int>(nums[i],1));
        //     }
        // }
        // map<int,int>::iterator hashptr;
        // hashptr = hash.begin();
        // vector<int> sumnum(hash.size());
        // int i = 0;
        // for(;hashptr!=hash.end();hashptr++)
        // {
        //     sumnum[i] = hashptr->first*hashptr->second;
        //     i+=1;
        // }
        vector<int> sumnum(*max_element(nums.begin(), nums.end()) + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            sumnum[nums[i]]++;
        } // hash表的构建
        vector<int> maxp(sumnum.size());
        maxp[0] = sumnum[0];
        maxp[1] = max(sumnum[0], sumnum[1]);
        for (int i = 2; i < sumnum.size(); i++)
        {
            maxp[i] = max((maxp[i - 2] + sumnum[i]*i), maxp[i - 1]);
        }
        return maxp.back();
    }
};

int main()
{
    Solution S;
    vector<int> v;
    v = {2, 2, 3, 3, 3, 4};
    S.deleteAndEarn(v);
    return 0;
}