#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid){
        // 4ms > 96.86%, 9.7MB > 87.91%
        const size_t len = grid.size();
        int increase = 0;
        vector<int> colmax(len, 0), rowmax(len, 0);
        for (int i = 0; i < len; ++i){
            for (int j = 0; j < len; ++j){
                rowmax[i] = max(rowmax[i], grid[i][j]);
                colmax[j] = max(colmax[j], grid[i][j]);
            }
        }
        
        for (int i = 0; i < len; ++i){
            for (int j = 0; j < len; ++j){
                increase += (min(rowmax[i], colmax[j]) - grid[i][j]);
            }
        }
        return increase;
    }
};