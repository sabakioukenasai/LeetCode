#include <vector>
#include <cstring>

using std::pair;
using std::vector;

class Solution{
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>> &obstacleGrid) {
        const int row = obstacleGrid.size();    // 行数
        const int col = obstacleGrid[0].size(); // 列数
        vector<vector<char>> choice(row, vector<char>(col, 'N')); // 记录每个节点选择的下一个节点
        vector<vector<int>> path;               // 最终路径

        if (obstacleGrid[0][0] == 1)
            return path;

        choice[row - 1][col - 1] = 'R';
        for (int j = col - 2; j >= 0; --j) {
            if (obstacleGrid[row - 1][j + 1] == 0 && choice[row - 1][j + 1] != 'N') {   // 如果右边有路
                choice[row - 1][j] = 'R';
            }
        }

        for (int i = row - 2; i >= 0; --i) {
            if (obstacleGrid[i + 1][col - 1] == 0 && choice[i + 1][col - 1] != 'N') 
                choice[i][col - 1] = 'D';

            for (int j = col - 2; j >= 0; --j) {
                if (obstacleGrid[i][j] == 1)
                    continue;
                if (choice[i][j + 1] != 'N') {          // 如果右路通
                    choice[i][j] = 'R';
                }
                else if (choice[i + 1][j] != 'N' ) {    // 如果下路通
                    choice[i][j] = 'D';
                }
            }
        }
        int r = 0, c = 0;
        while(choice[r][c] != 'N') {
            if (choice[r][c] == 'R')
                path.emplace_back(r, ++c);
            else
                path.emplace_back(++r, c);
        }
        return path;
    }
};