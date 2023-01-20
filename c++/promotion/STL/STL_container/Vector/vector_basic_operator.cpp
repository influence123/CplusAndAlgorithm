#include <iostream>
#include <vector>
// vector容器的概念和基本操作
// vector的数据结构与数组非常详实，也称为单端数组，不同之处在于数组是一个静态空间，而vector可以动态扩展
// 动态扩展的原理不是在原空间后续接新空间，而是找到更大的内存空间，然后将原数据拷贝到新空间，释放原空间

using namespace std;

void printvector(vector<int> &v)
{
    for (vector<int>::iterator i = v.begin(); i < v.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

// void test01()//vector的构造
// {
//     vector<int> v1;//默认的无参构造
//     for(int i = 0;i<10;i++)
//     {
//         v1.push_back(i);
//     }
//     printvector(v1);

//     vector<int> v2(v1.begin(),v1.end());//通过区间的方式进行构造
//     printvector(v2);

//     vector<int> v3(10,100);//n个elements的方式构造
//     printvector(v3);

//     vector<int> v4(v3);//拷贝构造
//     printvector(v4);
// }

void test02() // vector的赋值操作
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
        v1.push_back(i);
    printvector(v1);
    vector<int> v2;
    v2 = v1; // vector类中等号运算符的重载，即vector & operator=（const vector &vec）
    printvector(v2);
    vector<int> v3;
    v3.assign(v1.begin(), v1.end()); // 使用assign进行赋值
    printvector(v3);
    vector<int> v4;
    v4.assign(10, 100);
    printvector(v4);
}

void test03() // 对vector的容量和大小进行操作
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    cout << v1.empty() << endl;
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;
    v1.resize(15); // 重新指定大小后，如果新值更大，则在无值的地方自动填零
    printvector(v1);
    v1.resize(5);
    printvector(v1);    // 如果新值更小，则会删除后面的值
    v1.resize(10, 100); // 可以指定默认填充值
    printvector(v1);
}

void test04() // vector的插入和删除
{
    vector<int> v1;
    v1.push_back(10); // 尾插法插入数据
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    printvector(v1);
    v1.pop_back();                 // 尾删法
    v1.insert(v1.begin(), 100);    // 提供一个迭代器进行插入
    v1.insert(v1.begin(), 2, 100); // insert的重载，选择一个迭代器，插入n个值m
    printvector(v1);
    v1.erase(v1.begin()); // 提供一个迭代器进行删除
    printvector(v1);
    v1.erase(v1.begin(), v1.end()); // 提供两个迭代器，删除他们之间的数据
    printvector(v1);
    v1.clear(); // 清空操作
}

void test05() // vector的数据存储
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    cout << v1.at(5) << endl;   // 返回索引的数据
    cout << v1[5] << endl;      // 重载[]
    cout << v1.front() << endl; // 返回首个元素
    cout << v1.back() << endl;  // 返回末尾元素
}

void test06() // vector中的互换容器操作
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    vector<int> v2;
    for (int i = 9; i >= 0; i--)
    {
        v2.push_back(i);
    }
    printvector(v2);

    v1.swap(v2); // 互换容器的接口
    printvector(v1);
    printvector(v2);

    // swap的实际用途：巧用可以收缩空间
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "v的容量为" << v.capacity() << endl; // 容量为1.3倍左右
    cout << "v的大小为" << v.size() << endl;
    v.resize(10);
    cout << "v的容量为" << v.capacity() << endl;
    cout << "v的大小为" << v.size() << endl;
    vector<int>(v).swap(v); // 原理为：vector<int> x(v),当x去掉后，类似一个拷贝构造，拷贝构造会复制大小一样的容器，但是是匿名对象，swap交换匿名对象和v的指针，匿名对象在本句执行完之后就会释放
    cout << "v的容量为" << v.capacity() << endl;
    cout << "v的大小为" << v.size() << endl;
}

void test07() // vector预留空间用途：减少vector在动态扩展容量时的扩展次数
{
    vector<int> v1;
    //利用reserve预留空间
    v1.reserve(10000);
    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }
    cout << "开辟了多少次内存" << num << endl;
}

int main()
{
    test07();
    return 0;
}