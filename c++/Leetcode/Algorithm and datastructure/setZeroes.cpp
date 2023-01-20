#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> pos;
        for(int i = 0 ; i < row;i++)
        {
            for(int j = 0; j < column; j++)
            {
                if(matrix[i][j]==0)
                {
                    pos.push_back({i,j});
                }
            }
        }
        for(int i = 0; i < pos.size(); i++)
        {
            matrix[pos[i][0]].assign(column,0);//每行赋0
            for(int j = 0 ; j < row;j++)
            {
                matrix[j][pos[i][1]] = 0;//每列赋0
            }
        }
        matrix;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> v;
    v.push_back({1,1,1});
    v.push_back({1,0,1});
    v.push_back({1,1,1});
    // [[1,1,1],[1,0,1],[1,1,1]]
    S.setZeroes(v);
    return 0;
}