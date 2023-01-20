#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> hash;
        hash.push_back(nums[0]);
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.back() != nums[i])
            {
                hash.push_back(nums[i]);
            }
        }
        if (hash.size() != nums.size())
        {
            return true;
        }
        else
            return false;
    }
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    Solution S;
    cout<<S.containsDuplicate(v)<<endl;
    return 0;
}