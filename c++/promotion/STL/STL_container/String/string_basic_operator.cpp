#include <iostream>
#include <string>
// string容器的基本概念和操作
// string本质上是一个类
// string与char*的区别：char*是一个字符型指针，而string是一个类，类内封装了char*类型，用以管理这个字符串，故string是一个char*型的容器
// string类内部封装了许多成员函数：包括查找（find）、拷贝（copy）、删除（delete）、替换（replace）、插入（insert）
// 类内的内存管理由string自身负责，不需要担心越界
using namespace std;

// void test01()//string构造函数，进行初始化
// {
//     string s1; // 直接声明字符串
//     const char *str = "hello world";
//     string s2(str); // 以char*的方式拷贝构造s2
//     cout << s2 << endl;
//     string s3(s2); // 以string类的类型拷贝构造s3，srting s3（const string & str）
//     cout << s3 << endl;
//     string s4(10, 'a');
//     cout << s4 << endl;
// }

// void test02() // 在初始化之后进行赋值操作：包括重载operator=运算符和成员函数assign
// {
//     string s1;
//     s1 = "hello world"; // 在这里由于string是一个类，并非内置数据类型，等号被重载为string & operator = （const char * str）
//     cout << s1 << endl;
//     string s2;
//     s2 = s1; // 等号被重载为string & operator = (const sting & s)
//     cout << s2 << endl;
//     string s3;
//     s3 = 'a'; // 等号被重载为string & operator = (const char c)
//     cout << s3 << endl;

//     string s4;
//     s4.assign("hello world");//成员函数，string & assign(const char* str)
//     cout << s4 << endl;
//     s4.assign("hello world",10);//将字符串的前n个数值赋给左值，string & assign（const char* str，int n）
//     cout << s4 << endl;
//     s4.assign(s3);//string & assign(const string & str)
//     cout << s4 << endl;
//     s4.assign(10,'a');//string & assign(int n,const char c)
//     cout << s4<< endl;
// }

// void test03() // 字符串拼接:包括重载的operator+=运算符和成员函数append,传入参数包括char*、string &、char
// {
//     string s1("hello");
//     const char *str = "hello world";
//     s1 += str;
//     cout << s1 << endl;
//     s1.append(str);
//     s1.append("hello");
//     s1.append("hhhhhhhhhhhhh", 1);
//     s1.append(str, 6, 10); // 从str的第六个字符到第十个字符截取并拼接到s1上
//     cout << s1 << endl;
// }

void test04()//字符串的查找和替换：查找包括两个成员函数find和rfind，区别为从头开始还是从尾开始，若没有查找到，则会返回-1；替换为成员函数replace
{}

void test05()//字符串之间的比较：由成员函数compare，根据ascii码的值来比较，若是=则返回0，若是>则返回1，若是<则返回-1，传入的参数包括const string &和const char* str
{}

void test06()//字符串中的字符存取。包括重载运算符oprator[]和成员函数at
{}

void test07()//字符串中的插入和删除：插入为成员函数insert；删除为成员函数erase
{}

void test08()//字符串中子串的获取：获取子串为成员函数substr
{}

int main()
{
    // test01();
    // test02();
    // test03();
    test04();
    return 0;
}