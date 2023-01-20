#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        char sign = s[0];
        vector<int> record(s.size());
        for(int i = 1;i < s.size(); i++)
        {
            if(s[i]==sign)
            {
                record[i] = 1;
            }
        }
    }
};

int main()
{
    return 0;
}