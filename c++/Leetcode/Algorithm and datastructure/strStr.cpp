#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int left = 0;
        int right = 0;
        int needleptr = 0;
        int flag = 1;
        int ans = 0;
        while (left < haystack.size() && right < haystack.size())
        {
            if (haystack[right] == needle[needleptr])
            {
                right++;
                needleptr++;
            }
            else
            {
                needleptr = 0;
                right = left;
                ans = left;
                flag = 1;
            }
            if (needleptr == needle.size())
            {
                return ans;
            }
            if (flag == 1)
            {
                left++;
                if (haystack[left] == needle[0])
                    flag = 0;
            }
        }
        return -1;
    }
};

int main()
{
    Solution S;
    cout << S.strStr("abc", "c") << endl;
    return 0;
}