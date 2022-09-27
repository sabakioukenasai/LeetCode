#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution{
public:
    bool CheckPermutation(string s1, string s2){
        if (s1.size() != s2.size())
            return false;

        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (char c : s1){
            cnt1[c - 'a']++;
        }
        for (char c : s2){
            cnt2[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
            if (cnt1[i] != cnt2[i])
                return false;
        return true;
    }
};