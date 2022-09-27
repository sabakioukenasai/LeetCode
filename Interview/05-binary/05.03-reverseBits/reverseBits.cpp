#include <algorithm>

using std::max;

class Solution{
public:
    int reverseBits(int num) {
        unsigned int mask = 1;
        int low = -1, brige = -1, maxlen = 0;
        for (int i = 0; i < 32; ++i) {
            if ((num & mask) == 0) {
                maxlen = std::max(maxlen, i - low);
                low = brige;
                brige = i;
            }
            mask <<= 1;
        }
        maxlen = max(maxlen, 31 - low);
        return maxlen;
    }
};