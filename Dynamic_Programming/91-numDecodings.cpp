#include<vector>
#include<iostream>
using namespace std;

class Solution{
private:
    bool is_exist(const string two){
        if(two < "27" && two > "09")
            return true;
        return false;
    }
public:
    int numDecodings(string s){
        if (s[0] == '0')
            return 0;

        int len = s.size();
        //vector<int> dp(len + 1, 1);
        int answer = 0, pre = 1, prepre = 1;
        for (int i = 2; i <= len; i++){
            string two(s, i - 2, 2);
            if(s[i - 1] == '0')
                //dp[i] = is_exist(two) ? dp[i - 2] : 0;
                answer = is_exist(two) ? prepre : 0;
            else
                //dp[i] = dp[i - 1] + (is_exist(two) ? dp[i - 2] : 0);
                answer = pre + (is_exist(two) ? prepre : 0);
            prepre = pre;
            pre = answer;
        }
        //return dp[len];
        return answer;
    }
};


int main(){
    Solution S;
    cout << S.numDecodings("101");
}