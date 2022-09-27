#include <vector>

using std::vector;

class Solution{
public:
    void setZeroes(vector<vector<int>>& matrix){
        const int rowlen = matrix.size();
        if (rowlen == 0)
            return;
        const int collen = matrix[0].size();
        if (collen == 0)
            return;
        vector<bool> zeroCol(collen, false), zeroRow(rowlen, false);
        for (int i = 0; i < rowlen; ++i){
            for (int j = 0; j < collen; ++j){
                if (!matrix[i][j]){
                    zeroCol[j] = true;
                    zeroRow[i] = true;
                }
            }
        }

        vector<int> rawRow;
        for (int i = 0; i < rowlen; ++i){
            if (zeroRow[i])
                matrix[i].assign(collen, 0);
            else
                rawRow.push_back(i);
        }
        for (int j = 0; j < collen; ++j){
            if (zeroCol[j]){
                for (int row : rawRow)
                    matrix[row][j] = 0;
            }
        }
    }
};