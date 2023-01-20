#include <iostream>
#include <vector>

using namespace std;

// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int left = 0;
//         int right = nums.size() - 1;
//         int lsum = 0, rsum = 0;
//         if (left == right)
//         {
//             return nums[left];
//         }
//         while (left <= right)
//         {
//             if (nums[left] + lsum <= 0 && nums[left] > 0)
//             {
//                 lsum = nums[left];
//             }
//             else if ((nums[left] + lsum <= 0) && nums[left] <= 0)
//             {
//                 lsum = 0;
//             }
//             else if (0 <= nums[left] + lsum)
//             {
//                 lsum += nums[left];
//             }
//             left++;
//             if (left < right)
//             {
//                 if (nums[right] + rsum <= 0 && nums[right] > 0)
//                 {
//                     rsum = nums[right];
//                 }
//                 else if ((nums[right] + rsum <= 0) && nums[right] <= 0)
//                 {
//                     rsum = 0;
//                 }
//                 else if ((nums[right] + rsum) >= 0)
//                 {
//                     rsum += nums[right];
//                 }
//                 right--;
//             }
//         }
//         return lsum + rsum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};


int main()
{
    Solution S;
    vector<int> v;
    v.push_back(-2);
    v.push_back(1);
    v.push_back(-3);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(-5);
    v.push_back(4);
    cout << S.maxSubArray(v) << endl;
    return 0;
}