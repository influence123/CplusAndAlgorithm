#include <iostream>
#include <list>
#define Endl endl
#include <algorithm>
// list（链表容器）的基本概念和操作：链表是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
// 链表有一系列结点组成，结点由存储数据元素的数据域和存储下一个结点地址的指针域组成，STL中的链表是一个双向循环链表
using namespace std;

void printlist(const list<int> &l)
{
    for (list<int>::const_iterator i = l.begin(); i != l.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() // list构造
{
    list<int> l; // 无参构造
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    printlist(l);
    list<int> l2(l.begin(), l.end()); // 区间构造
    printlist(l2);
    list<int> l3(l); // 拷贝构造
    printlist(l3);
    list<int> l4(10, 1000);
    printlist(l4);
}

void test02() // list赋值
{
    list<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    printlist(l);
    list<int> l2;
    l2.assign(l.begin(), l.end()); // 区间赋值
    printlist(l2);
    list<int> l3;
    l3.assign(10, 100);
    printlist(l3);
    list<int> l4;
    l4 = l3; // 运算符重载operator=
    printlist(l4);
    l3.swap(l); // 交换两个链表
    printlist(l);
    printlist(l3);
}

void test03() // list容器中的大小操作
{
    list<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    printlist(l);
    cout << l.size() << endl;
    cout << l.empty() << Endl;
    l.resize(5);
    printlist(l);
    l.resize(10, 100);
    printlist(l);
}

void test04() // list容器的插入和删除操作
{
    list<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    printlist(l);
    l.pop_back();
    printlist(l);
    l.push_front(-1);
    printlist(l);
    l.pop_front();
    printlist(l);
    l.remove(5); // 成员函数remove，删除所有与element值匹配的元素
    printlist(l);
}

void test05()//list容器的数据存储操作
{
    list<int> l; 
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    printlist(l);
    cout<<l.front()<<endl;
    cout<<l.back()<<endl;
}

void test06()//list容器的反转和排序函数
{
    list<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    printlist(l);
    l.reverse();//反转链表
    printlist(l);
    //sort(l.begin(),l.end());报错原因为，所有不支持随机访问迭代器的容器，不能使用标准算法
    l.sort();//升序排序
    printlist(l);
}

int main()
{
    test06();
    return 0;
}