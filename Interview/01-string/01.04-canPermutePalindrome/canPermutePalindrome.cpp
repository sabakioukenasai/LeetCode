#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution{
public:
    bool canPermutePalindrome(string s){
        vector<bool> even(128, true);
        for (char c : s)
            even[(unsigned)c] = !even[(unsigned)c];
        int cnt = 0;
        for (int i = 0; i < 128; ++i)
            if (!even[i])
                ++cnt;
        return cnt < 2;
    }
};