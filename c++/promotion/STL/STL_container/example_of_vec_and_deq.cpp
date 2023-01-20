#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define Endl endl

using namespace std;

class player // 创建选手类
{
public:
    player(char name, int score)
    {
        mname = name;
        mscore = score;
    }
    char mname;
    int mscore;
};

int main()
{
    vector<player> v;
    string nameseed = "ABCDE";
    int scoreseed = 0;
    for (int i = 0; i < 5; i++)
    {
        player p(nameseed[i], scoreseed);
        v.push_back(p);
    } // 创建五名选手
    for (vector<player>::iterator i = v.begin(); i < v.end(); i++)
    {
        deque<int> d;
        for (int j = 0; j < 10; j++)
        {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        int sum = 0;
        for (deque<int>::iterator k = d.begin(); k < d.end(); k++)
        {
            sum += *k;
        }
        int mean = sum / d.size();
        i->mscore = mean;
    }
    for (vector<player>::iterator i = v.begin(); i < v.end(); i++)
    {
        cout << i->mname << " " << i->mscore << endl;
    }
    return 0;
}