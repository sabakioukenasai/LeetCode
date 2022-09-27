#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size(), left = 0, sublen = 0;
        string answer = "";
        vector<bool> dp(len, 1);

        //对于空字符串最大回文子串为空串
        if (len == 0)
            return answer;

        // 动态规划
        for (int i = len - 1; i >= 0; i--)
        {
            int pre = 1;
            for (int j = i; j != len; j++)
            {
                int temp = dp[j];
                dp[j] = (s[i] == s[j]) && pre;

                if (dp[j] && j - i >= sublen)
                {
                    left = i;
                    sublen = j + 1 - i;
                }
                pre = temp;
            }
        }
        answer = s.substr(left, sublen);
        return answer;
    }
};

int main()
{
    string s = "ac";
    Solution T;
    cout << T.longestPalindrome(s) << endl;
}