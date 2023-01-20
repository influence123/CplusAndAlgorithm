#include <iostream>
#include <stack>
//stack栈容器的基本概念和操作：先进后出，不允许遍历
using namespace std;

void printstack(const stack<int> &s)
{
    for(int i = s.size();i > 0;i--)//得到栈的大小
    {
        cout<<s.top()<<" ";//得到栈顶元素
    }
    cout<<endl;
}

void test01()
{
    stack<int> s;//默认构造函数
    for(int i = 0;i < 10;i++)
    {
        s.push(i);//入栈操作
    }
    printstack(s);
    stack<int> s1;
    s1 = s;//重载运算符operator=，属于赋值操作
    printstack(s1);
    stack<int> s2(s);//拷贝构造函数
    printstack(s2);
    cout<<s2.empty()<<endl;
}

int main()
{
    test01();
    return 0;
}