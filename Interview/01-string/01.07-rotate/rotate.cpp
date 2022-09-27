#include <vector>

using std::vector;

class Solution{
public:
    void rotate(vector<vector<int>>& matrix){
        int len = matrix.size() - 1, temp, rowend = (len + 1) / 2, colend = len / 2 + 1;
        for (int i = 0; i < rowend; ++i){
            for (int j = 0; j < colend; ++j){
                temp = matrix[i][j];
                matrix[i][j] = matrix[len - j][i];
                matrix[len - j][i] = matrix[len - i][len - j];
                matrix[len - i][len - j] = matrix[j][len - i];
                matrix[j][len - i] = temp;
            }
        }
    }
};