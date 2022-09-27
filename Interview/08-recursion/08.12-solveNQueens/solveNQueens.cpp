#include <vector>
#include <string>

using std::string;
using std::vector;

// 4ms > 87.83%, 7.3MB > 51.17%
class Solution{
private:
    vector<vector<string>> ans;     // 解空间
    vector<string> board;           // 棋盘的一个snapshot
    vector<bool> col;               // 标记某一行是否可以放置皇后
    int boardsize;

    // 尝试在第 row 行放置皇后
    void dfs(int row) {
        if (row == boardsize) {     // 如果所有行都放置了皇后，产生一个解
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < boardsize; ++i) {
            if (col[i]) {           // 如果第i列没有放置过皇后
                int x = row, y = i;
                // 向左上方寻找其他皇后
                while(--x >= 0 && --y >= 0) {
                    if (board[x][y] == 'Q')
                        goto NEXTCOL;
                }
                x = row;
                y = i;
                // 向右上方寻找其它皇后
                while(++x < boardsize && --y >= 0) {
                    if (board[x][y] == 'Q')
                        goto NEXTCOL;
                }

                // 如果对角线方向上都没有其它皇后，说明这个位置是可以方式皇后的。
                col[i] = false;
                board[row][i] = 'Q';
                // 放置好皇后后，再在下一行放置皇后
                dfs(row + 1);
                // 提起皇后，尝试其他可能
                board[row][i] = '.';
                col[i] = true;
            }
            NEXTCOL:
                continue;
        }
        return;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        col = vector<bool>(n, true);
        boardsize = n;

        dfs(0);
        return ans;
    }
};