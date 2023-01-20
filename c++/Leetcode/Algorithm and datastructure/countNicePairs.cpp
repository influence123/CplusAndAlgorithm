#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>
#define mod (int)(1e9 + 7)

using namespace std;

class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        unordered_map<int, int> store;        // key用于存储换位相减结果，value用于存储换位相减结果为key值的数目
        long long sum = 0;                    // 存储最终结果
        for (int i = 0; i < nums.size(); i++) // 遍历一次，求出每个值换位相减结果，记录在map中
        {
            string str;
            str = to_string(nums[i]);
            reverse(str.begin(), str.end()); // 反转字符串
            long long fnums = atoi(str.c_str());
            int flag = 0;
            for (unordered_map<int, int>::iterator j = store.begin(); j != store.end(); j++)
            {
                if (abs(nums[i] - fnums) == j->first)
                {
                    j->second++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                store.insert(pair<long long, long long>(abs(nums[i] - fnums), 1));
            }
        }
        for (unordered_map<int, int>::iterator j = store.begin(); j != store.end(); j++)
        {
            if (j->second > 1)
            {
                sum += (j->second) * (j->second - 1) / 2;
            }
        }
        sum %= mod;
        return sum;
    }
};

int main()
{
    cout << mod << endl;
    vector<int> v;
    v = {13, 10, 35, 24, 76};
    Solution S;
    cout << S.countNicePairs(v) << endl;
    return 0;
}