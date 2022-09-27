class Solution {
private:
    bool isRotable(int num) {
        int diffRota = 0;
        while(num > 0) {
            int p = num % 10;
            num /= 10;
            if (p == 2 || p == 5 || p == 6 || p == 9)
                ++diffRota;
            else if (p != 0 && p != 1 && p != 8)
                return false;
        }
        return diffRota > 0;
    }

public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (isRotable(i))
                ++ans;

        return ans;
    }
};