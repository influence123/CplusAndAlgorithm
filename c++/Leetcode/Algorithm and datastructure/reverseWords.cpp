#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        char sign = ' ';
        int left = 0;
        int right;
        char temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == sign)
            {
                right = i - 1;
                while (left <= right)
                {
                    temp = s[right];
                    s[right] = s[left];
                    s[left] = temp;
                    left++;
                    right--;
                }
                left = i + 1;
            }
        }
        right = s.size()-1;
        while (left <= right)
        {
            temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
        return s;
    }
};

int main()
{
    Solution S;
    S.reverseWords("Let's take LeetCode contest");
    return 0;
}