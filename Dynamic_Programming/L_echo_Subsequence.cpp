#include<iostream>
#include<vector>
using namespace std;

int LechoS(string S);

int LechoS(string S){
    int len = S.size();
    //注释内容为压缩空间复杂度版
    vector<vector<int>> dp(len, vector<int>(len, 0));
    //vector<int> dp(len, 1);

    for (int i = 0; i != len; i++)
        dp[i][i] = 1;

    for (int i = len - 2; i >= 0; i--){
        //int pre = 0;
        for (int j = i + 1; j != len; j++){
            //int temp = dp[j]
            if(S[i] == S[j]){
                dp[i][j] = dp[i + 1][j - 1] + 2;
                //dp[j] = pre + 2;
            }
            else{
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                //dp[j] = max(dp[j], dp[j - 1]);
            }
            //pre = temp;
        }
    }

    return dp[0][len - 1];
    //return dp[len-1];
}

int main(){
    string str = "aafhfdfdsga";
    cout << LechoS(str) << endl;
    return 0;
}