#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
                return mid;//查找到了返回mid
        }
        return left;//没查找到不满足left<=right条件退出循环，最终有right<target<=left
    }
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(6);
    Solution S;
    cout<<S.searchInsert(v,0)<<endl;
    return 0;
}