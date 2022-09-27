#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> permutation(string S) {
        std::sort(S.begin(), S.end());
        vector<string> res;
        res.push_back(S);
        while(std::next_permutation(S.begin(), S.end())) {
            res.push_back(S);
        }

        return res;
    }
};