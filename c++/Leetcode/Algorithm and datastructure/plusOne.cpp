#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // int bit = digits.size();
        // int num = 0;
        // int temp = 0;
        // if (digits.size() == 1)
        // {
        //     if (digits[0] == 9)
        //     {
        //         digits[0] = 1;
        //         digits.push_back(0);
        //         return digits;
        //     }
        //     digits[0] += 1;
        //     return digits;
        // }
        // for (int i = 0; i < digits.size(); i++)
        // {
        //     temp = digits[i] * ((int)pow(10, bit - 1));
        //     bit--;
        //     num += temp;
        // }
        // num++;
        // vector<int> newdigits;
        // for (int i = digits.size() - 1; i > 0; i--)
        // {
        //     newdigits[i] = num % 10;
        //     num = (num - newdigits[i]) / 10;
        // }
        // return newdigits;

        //         当我们对数组digits加一时，我们只需要关注digits的末尾出现了多少个9即可。我们可以考虑如下的三种情况：如果digits的末尾没有9，那么我们直接将末尾的数加一，得到并返回；

        // 如果digits 的末尾有若干个9，那么我们只需要找出从末尾开始的第一个不为9的元素，即将该元素加一，得到。随后将末尾的9全部置零，得到并返回。

        // 如果digits 的所有元素都是9，我们只需要构造一个长度比digits多1的新数组，将首元素置为1，其余元素置为0即可。
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] != 9)
            {
                ++digits[i];
                for (int j = i + 1; j < n; ++j)
                {
                    digits[j] = 0;
                }
                return digits;
            }
        }
        // digits 中所有的元素均为 9
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};

    int main()
    {
        Solution S;
        vector<int> v;
        v = {9, 9};
        S.plusOne(v);
        return 0;
    }