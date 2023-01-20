#include <iostream>
#include <map>
#define Endl endl
// map和multimap容器的基本概念和操作
// map中的所有元素都是pair，pair中的第一个元素为key值，用于索引，pair中的第二个元素为value值，是真实值，map容器中的所有元素会根据key值自动排序
// map和multimap属于关联式容器，底层结构由二叉树实现
// 可以根据key值快速找到value值，区别是map不能有重复的key，multimap可以有重复的key
using namespace std;

void printmap(const map<int, int, mycompare> &m)
{
    for (map<int, int, mycompare>::const_iterator i = m.begin(); i != m.end(); i++)
    {
        cout << (*i).second << " ";
    }
    cout << endl;
}

void test01() // map容器的构造和赋值操作
{
    map<int, int> m; // 无参构造
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    printmap(m);
    map<int, int> m2(m); // 拷贝构造
    printmap(m2);
    map<int, int> m3;
    m3 = m; // 赋值操作
    printmap(m3);
}

void test02() // map容器的大小和交换
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    printmap(m);
    cout << m.size() << endl;
    cout << m.empty() << Endl;
}

void test03() // map容器的查找和统计
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    printmap(m);
    map<int, int>::iterator i = m.find(2); // map的查找函数返回值为查找的key值的迭代器
    if (i != m.end())
    {
        cout << (*i).second << Endl;
    }
    cout << m.count(4) << endl;
}

class mycompare
{
    public:
    bool operator()(int v1, int v2)
    {
        return v1>v2;
    }
};

void test04()//map容器的排序
{
    map<int, int, mycompare> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(4, 40));
    m.insert(make_pair(5,50));
    //printmap(m);
    
}

int main()
{
    test04();
    return 0;
}