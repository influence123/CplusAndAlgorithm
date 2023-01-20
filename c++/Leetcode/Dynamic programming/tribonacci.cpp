#include <iostream>

using namespace std;

class Solution 
{
public:
    int tribonacci(int n) 
    {
        int f0 = 0, f1 = 1, f2 = 1;
        int fn = 0;
        int temp1,temp2;
        if(n==0)
        {
            return f0;
        }
        else if(n==1)
        {
            return f1;
        }
        else if(n==2)
        {
            return f2;
        }
        else
        {
            for(int i = 2; i<n;i++)
            {
                temp1 = f1;
                temp2 = f2;
                fn = f2+f1+f0;
                f2 = fn;
                f1 = temp2;
                f0 = temp1;
            }
            return fn;
        }
    }
};

int main()
{
    Solution S;
    cout<<S.tribonacci(25)<<endl;
    return 0;
}