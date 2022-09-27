#ifndef ProJectLCS
#define ProJectLCS

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int LCS(string S1, string S2){
        int n = S1.size(), m = S2.size(), pre = 0;
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            pre = 0;
            for (int j = 1; j <= n; j++)
            {
                int temp = dp[j];
                if(S1[i] == S2[j]){
                    dp[j] = pre + 1;
                }
                else{
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                pre = temp;
            }

        }

        return dp[n];
    }
};
#endif

int main(){
    string S1 = "aflagshasdflk", S2 = "akkjlfagdskjag";
    Solution S;
    cout << S.LCS(S1, S2) << endl;
    return 0;
}
