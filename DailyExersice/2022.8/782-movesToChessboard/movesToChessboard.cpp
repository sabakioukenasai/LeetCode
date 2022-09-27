#include <vector>
#include <iostream>

using std::abs;
using std::min;
using std::vector;

class Solution{
public:
    int movesToChessboard(vector<vector<int>> &board){
        const int n = board.size();         // 棋盘长宽
        int rowmask = 0, colmask = 0;
        for (int i = 0; i < n; ++i){        // 求出第一行和第一列的mask
            rowmask |= board[0][i] << i;
            colmask |= board[i][0] << i;
        }
        int reverseRowmask = ((1 << n) - 1) ^ rowmask;
        int reverseColmask = ((1 << n) - 1) ^ colmask;
        int rowcnt = 1, colcnt = 1;

        // 接下来检查每行是否和第一行相同或者相反
        // 每一列与第一列是否相同或相反
        for (int i = 1; i < n; ++i){
            int currRowmask = 0, currColmask = 0;
            for (int j = 0; j < n; ++j){
                currRowmask |= board[i][j] << j;
                currColmask |= board[j][i] << j;
            }
            // 如果出现任何超出这个范围之外的结果，返回-1
            if (currColmask == colmask)
                ++colcnt;
            else if (currColmask != reverseColmask)
                return -1;
            if (currRowmask == rowmask)
                ++rowcnt;
            else if(currRowmask != reverseRowmask)
                return -1;
        }

        int rowMoves = getMoves(rowmask, n, rowcnt);
        int colMoves = getMoves(colmask, n, colcnt);
        return rowMoves == -1 || colMoves == -1 ? -1 : rowMoves + colMoves;
    }

private:
    int getMoves(int mask, int n, int cnt){
        int ones = __builtin_popcount(mask);
        if (abs(n - (cnt << 1)) > 1 || abs(n - (ones << 1)) > 1)
            return -1;

        if (n & 1){         // 如果n是奇数
            if (ones == n >> 1)
                return (n >> 1) - __builtin_popcount(mask & 0xAAAAAAAA);
            else
                return ((n + 1) >> 1) - __builtin_popcount(mask & 0x55555555);
        }
        else {              // 如果n是偶数
            // 偶数位移动到全是一的移动步数
            int evenMoves = (n >> 1) - __builtin_popcount(mask & 0xAAAAAAAA);
            // 奇数位移动到全是一的移动步数
            int oddMoves = (n >> 1) - __builtin_popcount(mask & 0x55555555);
            return min(evenMoves, oddMoves);
        }
    }
};