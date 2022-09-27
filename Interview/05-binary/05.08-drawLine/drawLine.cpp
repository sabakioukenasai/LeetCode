#include <vector>

using std::vector;

// 4ms > 67.01%, 7.1MB > 74.74%
class Solution{
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> result(length, 0);
        int lbound = x1 % w, rbound = x2 % w, col = w >> 5, cnt = 0;
        unsigned int mask, end = (y + 1) * col;
        for (int i = y * col; i < end; ++i) {
            mask = 1 << 31;
            for (int j = 31; j >= 0; --j) {
                if (lbound <= cnt && cnt <= rbound) {
                    result[i] |= mask;
                }
                ++cnt;
                mask = mask >> 1;
            }
        }
        return result;
    }
};