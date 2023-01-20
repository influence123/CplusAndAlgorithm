#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size()-1;
        char temp;
        while(left<=right)
        {
            temp = s[right];
            s[right] = s[left];
            s[left] = temp;
            left++;
            right--;
        }
        //sssss
    }
};

int main()
{
    return 0;
}