#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = 0;
        int j = 0;
        vector<int> num;
        while(i<=m||j<=n)
        {
            if(nums1[i]<=nums2[j])
            {
                num.push_back(nums1[i]);
                i++;
            }
            else
            {
                num.push_back(nums2[j]);
                j++;
            }
        }
        nums1 = num;
    }
};

int main()
{
    return 0;
}