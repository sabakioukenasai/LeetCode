#include <vector>

using std::vector;

// 12ms > 97.19%, 12.6MB > 46.59%
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> sum_m(m);
        vector<int> sum_n(n);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                sum_m[i] += mat[i][j];
                sum_n[j] += mat[i][j];
            }
        }
        for(int i = 0; i < m; i++)
        {
            if (sum_m[i] != 1)
                continue;
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1 && sum_n[j] == 1)
                    result++;
            }
        }
        return result;
    }
};