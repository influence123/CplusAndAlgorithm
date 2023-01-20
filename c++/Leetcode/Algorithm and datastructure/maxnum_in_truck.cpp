#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mycompare(vector<int> &v1, vector<int> &v2)
{
    return v1[1] > v2[1];
}

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int sum = 0;
        int temp = truckSize;
        sort(boxTypes.begin(), boxTypes.end(), mycompare);
        for (vector<vector<int>>::iterator i = boxTypes.begin(); i != boxTypes.end(); i++)
        {
            temp = truckSize;
            if ((temp -= (*i)[0]) >= 0)
            {
                sum += (*i)[1] * (*i)[0];
            }
            else
            {
                sum += (*i)[1] * truckSize;
            }
            truckSize -= (*i)[0];
            if (truckSize <= 0)
            {
                break;
            }
        }
        return sum;
    }
};

int main()
{
    vector<vector<int>> box;//[5,10],[2,5],[4,7],[3,9]
    box.push_back({5,10});
    box.push_back({2, 5});
    box.push_back({4, 7});
    box.push_back({3, 9});
    Solution S;
    cout << S.maximumUnits(box, 10) << endl;
    ;
    return 0;
}