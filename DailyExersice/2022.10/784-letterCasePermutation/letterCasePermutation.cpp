#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans = vector<string>();
        int m = 0;
        int n = s.size();
        for (auto c : s) {
            if (isalpha(c)) {
                ++m;
            }
        }

        int mask = 0;
        for (mask = 0; mask < (1 << m); ++mask)
        {
            string str = "";
            for (int j = 0, k = 0; j < n; j++) {
                if (isalpha(s[j]) && mask & (1 << k++)) {
                    str.push_back(toupper(s[j]));
                }
                else {
                    str.push_back(tolower(s[j]));
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};