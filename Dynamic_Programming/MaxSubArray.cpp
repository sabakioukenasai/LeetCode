#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int MaxSubArray(int array[], const int N){
        //传入一个数组以及数组内元素的个数
        if(N == 0)
            return 0;

        int i = 1, res = INT_MIN;
        vector<int> dp(N, 0);
        

        for (; i != N; i++){
            dp[i] = max(array[i], array[i] + dp[i - 1]);
        }

        for (i = 0; i != N; i++){
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(){
    int nums[7] = {-3, 1, 3, -1, 2, -4, 2};
    Solution S;
    int res = S.MaxSubArray(nums, 7);
    cout << res << endl;
}