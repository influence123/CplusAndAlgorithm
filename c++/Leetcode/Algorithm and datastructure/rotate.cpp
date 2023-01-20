#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int msize = nums.size();
        vector<int> v(msize);
        for(int i=0;i<msize;i++)
        {
            v[(i+k)%msize]=nums[i];
        }
        nums.swap(v);
    }
};

int main()
{
    Solution S;
    vector<int> v;
    v = {-1,-100,3,99};
    S.rotate(v,2);
    return 0;
}