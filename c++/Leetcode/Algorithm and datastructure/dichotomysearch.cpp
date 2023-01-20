#include <iostream>
#include <vector>
// 二分查找实现
using namespace std;

class Solution
{
public:
    int dichotomysearch(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (right - left) / 2 + left;
        while (left <= right)
        {
            mid = (right - left) / 2 + left;
            if (target > nums[mid])
            {
                left = mid+1;//
            }
            else if (target < nums[mid])
            {
                right = mid-1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int dichotomysearch(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1;
//         while(left <= right){
//             int mid = (right - left) / 2 + left;
//             int num = nums[mid];
//             if (num == target) {
//                 return mid;
//             } else if (num > target) {
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         }
//         return -1;
//     }
// };

int main()
{
    vector<int> v; //[-1,0,3,5,9,12]
    v.push_back(-1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(5);
    v.push_back(9);
    v.push_back(12);
    Solution S;
    cout << S.dichotomysearch(v, -1) << endl;
    return 0;
}