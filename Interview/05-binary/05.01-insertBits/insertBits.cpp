// 0ms > 100%, 5.7MB > 77.63%
class Solution{
public:
    int insertBits(int N, int M, int i, int j) {
        int m = M << i;
        unsigned int mask = 0xffffffff;
        unsigned int reverse = 1 << j;
        for (int k = j; k >= i; --k) {
            mask ^= reverse;
            reverse = reverse >> 1;
        }
        int n = N & mask;
        n |= m;
        return n;
    }
};

// mask 一定要设置成unsigned