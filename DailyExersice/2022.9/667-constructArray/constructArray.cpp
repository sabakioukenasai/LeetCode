#include <vector>

using std::vector;

// 0ms > 100%, 7.3MB > 60.34%
class Solution{
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(n, 0);
        int j = k >> 1, mode = k & 0x1;
        if (mode) {
            for (int i = 0; i < j; ++i) {
                result[i << 1] = i + 1;
                result[(i << 1) + 1] = n - i;
            }
        }
        else {
            for (int i = 0; i < j; ++i) {
                result[i << 1] = n - i;
                result[(i << 1) + 1] = i + 1;
            }
        }
        int num = j;
        for (int i = j << 1; i < n; ++i)
            result[i] = ++num;
        return result;
    }
};