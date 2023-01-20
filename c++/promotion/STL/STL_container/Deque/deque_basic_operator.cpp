#include <iostream>
#include <deque>
#include <algorithm>
#define Endl endl
// deque容器的基本概念和操作
// deque是一个双端数组，可以对头端进行插入删除操作
// deque和vector的区别：vector对头部进行操作的效率低，数据量越大效率越低；而deque的访问元素的速度比vector慢，这与两者的内部实现有关
// deque的内部工作原理：deque内部有个中控器，中控器上存储的是每个缓冲区的地址，在缓冲区中存放真实的数据
using namespace std;

void printdeque(const deque<int> &d) // 形参用const修饰后,迭代器也需要改为只读迭代器
{
    for (deque<int>::const_iterator i = d.begin(); i < d.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() // deque的构造函数
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);

    deque<int> d2(d1.begin(),d1.end());//通过区间的方式构造deque
    printdeque(d2);

    deque<int> d3(10,100);//通过有参构造函数
    printdeque(d3);

    deque<int> d4(d1);//通过拷贝构造
    printdeque(d4);
}

void test02()//deque容器的赋值操作
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    deque<int> d2;
    d2 = d1;//重载运算符operator=赋值
    printdeque(d2);
    d2.assign(10,100);
    printdeque(d2);
    d2.assign(d1.begin(),d1.end());
    printdeque(d2);
}

void test03()//deque大小操作
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    cout<<d1.empty()<<endl;//判断deque是否为空
    cout<<d1.size()<<endl;//得到deque的大小
    d1.resize(5);//重置deque的大小
    printdeque(d1);
    d1.resize(10);
    printdeque(d1);
}

void test04()//Deque的插入和删除操作
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    d1.push_back(10);
    printdeque(d1);
    d1.pop_back();
    printdeque(d1);
    d1.push_front(-1);
    printdeque(d1);
    d1.pop_front();
    printdeque(d1);

    d1.insert(d1.begin(),-1);
    printdeque(d1);
    d1.insert(d1.begin(),10,-1);
    printdeque(d1);
    d1.clear();
    printdeque(d1);
}

void test05()//deque容器的数据存取
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    cout<<d1.at(5)<<endl;
    cout<<d1[5]<<endl;
    cout<<d1.front()<<Endl;
    cout<<d1.back()<<endl;
}

void test06()//deque容器的排序操作
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    d1.insert(d1.begin(),10);
    printdeque(d1);
    sort(d1.begin(),d1.end());
    printdeque(d1);
}

int main()
{
    test06();
    return 0;
}