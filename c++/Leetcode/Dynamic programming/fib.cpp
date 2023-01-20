#include <iostream>

using namespace std;

class Solution 
{
public:
    int fib(int n) 
    {
        int f0 = 0;
        int f1 = 1;
        //int fn = (fn-1)+ (fn-2)
        int fn = 0;
        if(n==0)
        {
            return f0;
        }
        else if(n==1)
        {
            return f1;
        }
        else
        {
            for(int i = 1;i<n;i++)
            {
                int temp = f1;
                fn = f1 + f0;
                f1 = fn;
                f0 = temp;
            }
            return fn;
        }
    }
};

int main()
{
    Solution S;
    cout<<S.fib(2)<<endl;
    return 0;
}