#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
    int minDistance(string word1, string word2){
        int row = word1.size(), col = word2.size();
        vector<int> dp(col + 1, 0);

        for (int i = 1; i <= col; i++){
            dp[i] = i;
        }

        for (int i = 1; i <= row; i++){
            int pre = i - 1;
            dp[0] = i;
            for (int j = 1; j <= col; j++){
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[j] = pre;
                }
                else{
                    dp[j] = min(dp[j - 1], dp[j]) + 1;
                }
                pre = temp;
            }
        }

        return dp[col];
    }
};