#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> nums;
        int num1;
        int num2;
        int num;
        for(int i = 0; i < tokens.size();i++)
        {
            if(!tokens[i].compare("+"))
            {
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                num = num2+num1;
                nums.push(num);
            }
            else if(!tokens[i].compare("-"))
            {
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                num = num2-num1;
                nums.push(num);
            }
            else if(!tokens[i].compare("*"))
            {
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                num = num2*num1;
                nums.push(num);
            }
            else if(!tokens[i].compare("/"))
            {
                num1 = nums.top();
                nums.pop();
                num2 = nums.top();
                nums.pop();
                num = num2/num1;
                nums.push(num);
            }
            else
            {
                nums.push(stoi(tokens[i]));
            }
        }
        return nums.top();
    }
};

int main()
{
    Solution S;
    vector<string> v;
    v = {"2","1","+","3","*"};
    S.evalRPN(v);
    return 0;
}