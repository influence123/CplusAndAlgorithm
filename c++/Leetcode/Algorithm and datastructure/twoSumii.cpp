#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0;
        int right = numbers.size()-1;
        while(left<=right)
        {
            if(numbers[left]+numbers[right]>target)
            {
                right--;
            }
            else if(numbers[left]+numbers[right]<target)
            {
                left++;
            }
            else
            {
                break;
            }
        }
        vector<int> ans;
        ans = {left+1,right+1};
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> v;
    v = {2,7,11,15};
    S.twoSum(v,9);
    return 0;
}