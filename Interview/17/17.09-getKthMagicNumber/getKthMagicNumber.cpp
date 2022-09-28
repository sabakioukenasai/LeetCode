#include <vector>

using std::min;
using std::vector;

// 动态规划 0ms > 100%, 6MB > 76.68%
class Solution{
public:
    int getKthMagicNumber(int k) {
        vector<int> dp(k, 1);
        int p3 = 0, p5 = 0, p7 = 0;
        for (int i = 1; i < k; ++i)
        {
            dp[i] = min(3 * dp[p3], min(5 * dp[p5], 7 * dp[p7]));
            if (dp[i] == 3 * dp[p3]) {
                ++p3;
            } 
            if (dp[i] == 5 * dp[p5]) {
                ++p5;
            }
            if (dp[i] == 7 * dp[p7]) {
                ++p7;
            }
        }
        return dp[k - 1];
    }
};