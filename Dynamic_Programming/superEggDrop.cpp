#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> matrix;

matrix superEggDrop(int K, int N){
    // K表示鸡蛋的数量， N表示需要测量的楼层层数
    int Max_Try = N , m = 0;
    vector<vector<int>> dp(K + 1, vector<int>(Max_Try + 1, 0));
    while(dp[K][m] < N){
        m++;
        for (int k = 1; k <= K; k++)
        {
            dp[k][m] = dp[k - 1][m - 1] + dp[k][m - 1] + 1;
        }
    }

    return dp;
}

int main(){
    matrix dp = superEggDrop(3, 100);
    for (int i = 1; i <= 100; i ++)
        cout << "Try Times: " << i
             << ",  Max Test Floor: " << dp[3][i] << endl;
}