#include <string>
#include <vector>

using std::string;
using std::vector;

// 0ms > 100%, 6MB > 90.24%
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> table(26, -1);
        int ans = -1;
        for (int i = 0; i < s.size(); ++i) {
            ans = std::max(ans, i - table[s[i] - 'a'] - 1);
            table[s[i] - 'a'] = i;
        }
        return ans;
    }
};