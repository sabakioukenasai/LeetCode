#include <vector>
#include <string>
#include <cstring>
#include <tuple>

using std::string;
using std::tie;
using std::vector;

// 24ms > 81.84%, 11.1MB > 68.02%
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        int last[26][2];
        memset(last, 0xff, sizeof(int)*26*2);
        int ans = 0;
        for (int i = 0, sum = 0; i != n; ++i) {
            int c = s[i] - 'A';
            sum += (i - last[c][1] * 2 + last[c][0]);
            ans += sum;
            tie(last[c][0], last[c][1]) = {last[c][1], i};
        }
        return ans;
    }
};