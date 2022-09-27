// 0ms > 100%, 5.8MB > 61.51%
class Solution{
public:
    int multiply(int A, int B) {
        int ans = 0, a = A, b = B;
        while(b > 0) {
            if ((b & 0x1) == 1)
                ans += a;
            b >>= 1;
            a <<= 1;
        }
        return ans;
    }
};