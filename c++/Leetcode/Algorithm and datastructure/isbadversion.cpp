#include <iostream>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(isBadVersion(mid))
            {
                right = mid-1;
            }
            else if (!isBadVersion(mid))
            {
                left = mid+1;
            }
        }
        return left;
    }
};

int main()
{
    return 0;
}