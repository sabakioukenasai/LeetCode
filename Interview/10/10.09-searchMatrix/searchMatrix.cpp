#include <vector>

using std::vector;

// quite slow 196ms > 23%, 10.4MB > 58%
class Solution {
private:
    bool _searchMatrix(vector<vector<int>> &matrix, int target, int rowa, int rowb, int cola, int colb) {
        if (rowa > rowb || cola > colb)
            return false;
        int midrow = (rowa + rowb) >> 1, midcol = (cola + colb) >> 1;
        if (matrix[midrow][midcol] == target) {
            return true;
        }
        else if (matrix[midrow][midcol] > target) {
            return _searchMatrix(matrix, target, rowa, rowb, cola, midcol - 1) ||
                   _searchMatrix(matrix, target, rowa, midrow - 1, midcol, colb);
        }
        else {
            return _searchMatrix(matrix, target, rowa, midrow, midcol + 1, colb) ||
                   _searchMatrix(matrix, target, midrow + 1, rowb, cola, colb);
        }
    }
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        const int row = matrix.size(), col = matrix[0].size();
        int rowa = 0, rowb = row - 1;
        while (rowa < row && matrix[rowa][col - 1] < target)
            ++rowa;
        while (rowb > -1 && matrix[rowb][0] > target)
            --rowb;
        if (rowa == row || rowb == -1)
            return false;

        int cola = 0, colb = col - 1;
        while (cola < row && matrix[rowb][cola] < target)
            ++cola;
        while (colb > -1 && matrix[rowa][colb] < target)
            --colb;
        if (cola == col || colb == -1)
            return false;

        return _searchMatrix(matrix, target, rowa, rowb, cola, colb);
    }
};