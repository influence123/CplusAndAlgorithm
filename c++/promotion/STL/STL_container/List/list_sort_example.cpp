#include <iostream>
#include <list>
#include <string>

using namespace std;

class person
{
public:
    person(string name, int age, int height)
    {
        mname = name;
        mage = age;
        mheight = height;
    }
    string mname;
    int mage;
    int mheight;
};

void printperson(const list<person> &l)
{
    for (list<person>::const_iterator i = l.begin(); i != l.end(); i++)
    {
        cout << (*i).mname << " " << (*i).mage << " " << (*i).mheight << endl;
    }
}

bool compareperson(person &p1, person &p2) // 制定排序规则
{
    if (p1.mage == p2.mage)
    {
        return p1.mheight > p2.mheight;
    }
    else
        return p1.mage < p2.mage;
}

int main()
{
    list<person> l; // 创建容器
    person p1("zhangsan", 18, 180);
    person p2("lisi", 18, 190);
    person p3("wangwu", 19, 180);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    printperson(l);
    l.sort(compareperson); // sort函数接受自定义的排序规则
    printperson(l);
    return 0;
}