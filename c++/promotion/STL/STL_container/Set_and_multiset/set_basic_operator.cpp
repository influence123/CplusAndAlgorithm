#include <iostream>
#include <set>
#define Endl endl
//set/multiset容器的基本概念和操作：所有元素都会在插入时自动排序(为升序)
//set/multiset属于关联式容器，底层结构是用二叉树实现，区别为set不允许容器中有重复的元素，multiset允许容器中有重复的元素
using namespace std;

void printset(const set<int> &s)
{
    for(set<int>::const_iterator i = s.begin();i!=s.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<Endl;
}

void test01()//set容器的构造、赋值、插入操作
{
    set<int> s1;//默认构造
    s1.insert(10);//只有insert一种插入方式
    s1.insert(5);
    s1.insert(15);
    s1.insert(10);//插入重复的值后，编译器不会报错，但是并不会插入成功
    printset(s1);
    set<int> s2(s1);//拷贝构造
    printset(s2);
    set<int> s3;
    s3 = s1;//赋值
    printset(s3);
}

void test02()//set容器的大小和交换操作
{
    set<int> s1;
    s1.insert(10);
    s1.insert(5);
    s1.insert(15);
    printset(s1);
    cout<<s1.size()<<Endl;
    //s1.swap()
}

int main()
{
    test01();
    return 0;
}