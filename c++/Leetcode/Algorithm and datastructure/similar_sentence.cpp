#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution
{
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        deque<string> sent1; // 以空格分割两个字符串，分别存入两个vector容器中
        deque<string> sent2;
        char sap = ' ';
        int pos1 = 0;
        int pos2 = 0;
        for (int i = 0; i < sentence1.size(); i++)
        {
            if (sentence1[i] == sap)
            {
                sent1.push_back(sentence1.substr(pos1, i - pos1));
                pos1 = i + 1;
            }
            if (i == sentence1.size() - 1)
            {
                sent1.push_back(sentence1.substr(pos1, i - pos1 + 1));
            }
        }
        for (int i = 0; i < sentence2.size(); i++)
        {
            if (sentence2[i] == sap)
            {
                sent2.push_back(sentence2.substr(pos2, i - pos2));
                pos2 = i + 1;
            }
            if (i == sentence2.size() - 1)
            {
                sent2.push_back(sentence2.substr(pos2, i - pos2 + 1));
            }
        }
        // 对短句进行这样的循环遍历：从deque[0]开始找与长句相同，找到一个相同，则找deque[1]，。。。。找不到相同则从尾端开始，一直到找不到相同的字符串为止
        if (sent1.size() > sent2.size()) // 默认一为短句，否则交换两个容器
        {
            sent1.swap(sent2);
        }
        for (int i = 0; i < sent2.size(); i++)
        {
            if (!sent1.empty())
            {
                if (sent1[0].compare(sent2[i]))
                {
                    break;
                }
                else
                {
                    sent1.pop_front();
                }
            }
        }
        for (int j = sent2.size() - 1; j > 0; j--)
        {
            if (!sent1.empty())
            {
                if (!sent1[sent1.size() - 1].compare(sent2[j]))
                {
                    sent1.pop_back();
                }
                else
                {
                    break;
                }
            }
        }
        if (sent1.empty())
        {
            return true;
        }
        else
            return false;
        // 判断相似的条件为：一端以不相同结束，一端以相同结束（其中没有字符串记为不相同）
    }
};

int main()
{
    Solution S;
    cout << S.areSentencesSimilar("Eating right now", "Eating") << endl;
    return 0;
}