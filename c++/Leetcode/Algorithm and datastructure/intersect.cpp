#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> hash1;
        map<int, int> hash2;
        for (int i = 0; i < nums1.size(); i++)
        {
            int flag = 0;
            for (map<int, int>::iterator j = hash1.begin(); j != hash1.end(); j++)
            {
                if (nums1[i] == j->first)
                {
                    j->second++;
                    flag = 1;
                }
            }
            if (flag == 0)
                hash1.insert(pair<int, int>(nums1[i], 1));
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            int flag = 0;
            for (map<int, int>::iterator j = hash2.begin(); j != hash2.end(); j++)
            {
                if (nums2[i] == j->first)
                {
                    j->second++;
                }
            }
            if (flag == 0)
                hash2.insert(pair<int, int>(nums2[i], 1));
        }
        map<int, int>::iterator ptr1 = hash1.begin();
        map<int, int>::iterator ptr2 = hash2.begin();
        vector<int> ans;
        while (ptr1 != hash1.end() && ptr2 != hash2.end())
        {
            if (ptr1->first > ptr2->first)
            {
                ptr2++;
            }
            else if (ptr1->first < ptr2->first)
            {
                ptr1++;
            }
            else
            {
                int count = min(ptr1->second, ptr2->second);
                for (int i = 0; i < count; i++)
                {
                    ans.push_back(ptr1->first);
                }
                    ptr1++;
                    ptr2++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<int> nums1;
    vector<int> nums2;
    nums1 = {4, 9, 5, 9, 4};
    nums2 = {9, 4, 9, 8, 4};
    S.intersect(nums1, nums2);
    return 0;
}