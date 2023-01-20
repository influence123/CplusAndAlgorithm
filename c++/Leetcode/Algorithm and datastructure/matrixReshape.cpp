#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        if (mat.size() * mat[0].size() != r * c)
        {
            return mat;
        }
        else
        {
            vector<int> temp;
            temp = mat[0];
            for (int i = 1; i < mat.size(); i++)
            {
                temp.insert(temp.end(), mat[i].begin(), mat[i].end());
            }
            vector<vector<int>> ans(r);//二维数组给其赋值时需要初始化
            int begin = 0;
            for (int i = 0; i < r; i++)
            {
                for(int j = 0;j < c;j++)
                {
                    ans[i].push_back(temp[begin+j]);
                }
                begin+=c;
            }
            return ans;
        }
    }
};

int main()
{
    Solution S;
    vector<vector<int>> v;
    v = {{1,2},{3,4}};
    S.matrixReshape(v,1,4);
    return 0;
}