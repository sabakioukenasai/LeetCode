// 0ms > 100%, 5.8MB > 98.26%
class Solution{
private:
    int cnt25;
    int cnt10;
    int cnt5;
    unsigned int ans;

    void dfs() {
        ans = (ans + (long long)(cnt10 +cnt5 + 1) * (cnt10 + 1) % 1000000007) % 1000000007;
        if (cnt25 > 0) {
            --cnt25;
            cnt10 += 2;
            cnt5 += 1;
            cnt10 += (cnt5 / 2);
            cnt5 &= 0x1;
            dfs();
        }
    }

public:
    int waysToChange(int n) {
        cnt25 = n / 25;
        n %= 25;
        cnt10 = n / 10;
        n %= 10;
        cnt5 = n / 5;
        ans = 0;

        dfs();
        return ans % 1000000007;
    }
};