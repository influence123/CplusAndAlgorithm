#include <iostream>
#include <queue>
//queue（队列）的基本概念和操作：先进先出
using namespace std;

void test01()
{
    queue<int> q;//无参构造
    for(int i = 0;i < 10;i++)
    {
        q.push(i);
    }
    queue<int> q2(q);//拷贝构造
    queue<int> q3;
    q3 = q;//重载运算符operator=
    cout<<q.front()<<endl;//得到队首元素
    cout<<q.back()<<endl;//得到队尾元素
    cout<<q.size()<<endl;//队列大小
    cout<<q.empty()<<endl;//判空
    q.pop();//移除队首元素
    cout<<q.front()<<endl;
}

int main()
{
    test01();
    return 0;
}