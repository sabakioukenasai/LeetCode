#include <vector>
#include <string>

using std::string;
using std::vector;

// 0ms > 100.00%, 7MB > 98.56%
class Solution {
private:
    string item;
    vector<string> ans;

    void dfs(int idx, int left, int right) {
        if (right == 0){
            ans.push_back(item);
            return;
        }
        if (left < right) {
            item[idx] = ')';
            dfs(idx + 1, left, right - 1);
        }
        if (left > 0) {
            item[idx] = '(';
            dfs(idx + 1, left - 1, right);
        }
        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        item = string(2 * n, 0);
        ans = vector<string>();
        dfs(0, n, n);
        return ans;
    }
};