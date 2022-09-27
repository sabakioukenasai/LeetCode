#include <vector>
#include <string>
#include <unordered_set>

using std::string;
using std::swap;
using std::unordered_set;
using std::vector;

// 0ms > 100.00%, 7.1MB > 39.28%
class Solution {
public:
    vector<string> ans;
    void permute(string& s, int index) {
        int len = s.size();
        if(index >= len) {
            ans.push_back(s);
            return;
        }
        for(int i = index; i < len;) {
            if (i != index && s[i] == s[index]) {
                ++i;
                continue;
            }
            swap(s[index], s[i]);
            permute(s, index + 1);
            swap(s[index], s[i]);
            int j = i + 1;
            for (; j < len; ++j)
                if (s[i] != s[j])
                    break;
            i = j;
        }
        return;
    }
    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        permute(S, 0);
        return ans;
    }
};