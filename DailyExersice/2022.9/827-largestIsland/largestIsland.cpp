#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

class Solution{
private:
    int idx;
    int Size;
    vector<int> area;
    vector<vector<int>> group;

    void dfs(vector<vector<int>>& grid, int row, int col) {
        group[row][col] = idx;
        ++area[idx];
        if (row > 0 && grid[row - 1][col] == 1 && group[row - 1][col] == 0)
            dfs(grid, row - 1, col);
        if (row < Size - 1 && grid[row + 1][col] == 1 && group[row + 1][col] == 0)
            dfs(grid, row + 1, col);
        if (col > 0 && grid[row][col - 1] == 1 && group[row][col - 1] == 0)
            dfs(grid, row, col - 1);
        if (col < Size - 1 && grid[row][col + 1] == 1 && group[row][col + 1] == 0)
            dfs(grid, row, col + 1);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        idx = 0;
        Size = grid.size();
        area = vector<int>(1, 0);
        group = vector<vector<int>>(Size, vector<int>(Size, 0));
        
        // 给每一块陆地分组
        for (int i = 0; i < Size; ++i) {
            for (int j = 0; j < Size; ++j) {
                if ( grid[i][j] == 1 && group[i][j] == 0) {
                    area.push_back(0);
                    ++idx;
                    dfs(grid, i, j);
                }
            }
        }

        // for (int i = 0; i < Size; ++i) {
        //     for (int j = 0; j < Size; ++j)
        //         cout << group[i][j] << ", ";
        //     cout << endl;
        // }

        int ans = area[group[0][0]];
        // 遍历所有海洋,尝试连接两块陆地
        for (int i = 0; i < Size; ++i) {
            for (int j = 0; j < Size; ++j) {
                if ( grid[i][j] == 0) {
                    unordered_set<int> neighbor;
                    int cover = 1;
                    if (i > 0 && grid[i - 1][j] == 1) {
                        neighbor.emplace(group[i - 1][j]);
                    }
                    if (i < Size - 1 && grid[i + 1][j] == 1) {
                        neighbor.emplace(group[i + 1][j]);
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        neighbor.emplace(group[i][j - 1]);
                    }
                    if (j < Size - 1 && grid[i][j + 1] == 1) {
                        neighbor.emplace(group[i][j + 1]);
                    }
                    for (int groupnum : neighbor) {
                        cover += area[groupnum];
                    }
                    ans = std::max(ans, cover);
                }
            }
        }
        return ans;
    }
};