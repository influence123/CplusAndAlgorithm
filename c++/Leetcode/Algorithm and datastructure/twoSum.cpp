#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    friend ostream &operator<<(ostream &out,vector<int,allocator<int>> &v);
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
             hash.push_back(target - nums[i]);
        }
        for (int i = 0; i < hash.size(); i++)
        {
            for (int j = i+1; j < nums.size(); j++)
            {
                if (hash[i] == nums[j])
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

ostream &operator<<(ostream &out,vector<int,allocator<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
        out<<v[i]<<endl;
    return out;
}

int main()
{
    Solution S;
    vector<int> v;
    v = {2, 7, 11, 15};
    vector<int> v1(S.twoSum(v, 9));
    cout << v1 << endl;
    return 0;
}