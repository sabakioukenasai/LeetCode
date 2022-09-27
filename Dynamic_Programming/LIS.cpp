#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int LIS(int nums[], const int n){
        vector<int> dp(n, 1);
        int i, j, res = 0;

        for (i = 0; i <= n; i++){
            for (j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        for (i = 0; i != n; i++){
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main(){
    int nums[8] = { 10, 9, 2, 5, 3, 7, 101, 18 };
    Solution S;
    int res = S.LIS(nums, 8);
    printf("%d", res);
}