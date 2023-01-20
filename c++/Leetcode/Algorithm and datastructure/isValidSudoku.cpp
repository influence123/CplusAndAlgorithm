#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<char> row;
        vector<char> column;
        vector<char> ninecubes;
        // row = {'1','2','3','4','5','6','7','8','9'};
        // column = {'1','2','3','4','5','6','7','8','9'};
        // ninecubes = {'1','2','3','4','5','6','7','8','9'};
        for (int i = 0; i < 9; i++) // 检验行
        {
            row.clear();
            row.resize(10, 0);
            for (int j = 1; j < 10; j++)
            {
                if (board[i][j - 1] == 'j')
                {
                    row[j]++;
                }
            }
            for (int k = 1; k < 10; k++)
            {
                if (row[k] >= 2)
                {
                    return false;
                }
            }
        }
        for (int i = 0; i < 9; i++) // 检验列
        {
            column.clear();
            column.resize(10, 0);
            for (int j = 1; j < 10; j++)
            {
                if (board[j - 1][i] == 'j')
                {
                    column[j]++;
                }
            }
            for (int k = 1; k < 10; k++)
            {
                if (column[k] >= 2)
                {
                    return false;
                }
            }
        }
        for (int s = 0; s < 9; s += 3) // 检验cube
        {
            for (int t = 0; t < 9; t += 3)
            {
                for (int i = s; i < s + 3; i++)
                {
                    for (int j = t; j < t + 3; j++)
                    {
                        ninecubes.clear();
                        ninecubes.resize(10, 0);
                        for (int k = 1; k < 10; j++)
                        {

                            if (board[i][j] == 'k')
                            {
                                ninecubes[k]++;
                            }
                        }
                        for (int k = 1; k < 10; k++)
                        {
                            if (ninecubes[k] >= 2)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution S;
    vector<vector<char>> v;
    vector<char> v1(9);
    v1 = {"5", "3", ".", ".", "7", ".", ".", ".", "."};
    v.push_back({"5", "3", ".", ".", "7", ".", ".", ".", "."});
    v = {{"5", "3", ".", ".", "7", ".", ".", ".", "."}, {"6", ".", ".", "1", "9", "5", ".", ".", "."}, {".", "9", "8", ".", ".", ".", ".", "6", "."}, {"8", ".", ".", ".", "6", ".", ".", ".", "3"}, {"4", ".", ".", "8", ".", "3", ".", ".", "1"}, {"7", ".", ".", ".", "2", ".", ".", ".", "6"}, {".", "6", ".", ".", ".", ".", "2", "8", "."}, {".", ".", ".", "4", "1", "9", ".", ".", "5"}, {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
    S.isValidSudoku(v);
    return 0;
}