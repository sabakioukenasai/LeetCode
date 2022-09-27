#include<iostream>
#include<vector>
using namespace std;

int MinInsertions2d(string str){
    int len = str.size();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    //以下使用状态压缩
    //vector<int> dp(len, 0);

    for (int i = len - 1; i >= 0; i--){
        //int pre = 0;
        for (int j = i + 1; j != len; j++){
            //int temp = dp[j];
            if (str[i] == str[j]){
                dp[i][j] = dp[i + 1][j - 1];
                //dp[j] = pre;
            }
            else{
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                //dp[j] = min(temp, dp[j - 1]) + 1;
            }
            //pre = temp;
        }
    }

    return dp[0][len - 1];
    //return dp[len - 1];
}

int MinInsertions1d(string str){
    int len = str.size();
    vector<int> dp(len, 0);

    for (int i = len - 1; i >= 0; i--){
        int pre = 0;
        for (int j = i + 1; j != len; j++){
            int temp = dp[j];
            if (str[i] == str[j]){
                dp[j] = pre;
            }
            else{
                dp[j] = min(temp, dp[j - 1]) + 1;
            }
            pre = temp;
        }
    }

    return dp[len - 1];
}


int main(){
    string S = "aagatkjgadds";
    cout << MinInsertions1d(S) << endl;

}