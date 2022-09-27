#include <vector>

using std::vector;

// 0ms > 100%, 8MB > 63.24%
class Solution{
public:
    vector<int> decrypt(vector<int> &code, int k) {
        const int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) {
        }
        else if (k > 0) {
            int sum = 0, rbound = 0;
            for (; rbound < k; ++rbound)
                sum += code[rbound];
            ans[n - 1] = sum;

            for (int i = 0; i < n - 1; ++i) {
                sum -= code[i];
                sum += code[rbound];
                rbound = (rbound + 1) % n;
                ans[i] = sum;
            }
        }
        else {
            int sum = 0, lbound = n - 1;
            for (; lbound >= n + k; --lbound) {
                sum += code[lbound];
            }
            ans[0] = sum;

            for (int i = n - 1; i > 0; --i) {
                sum -= code[i];
                sum += code[lbound];
                lbound = (n + lbound - 1) % n;
                ans[i] = sum;
            }
        }
        
        return ans;
    }
};