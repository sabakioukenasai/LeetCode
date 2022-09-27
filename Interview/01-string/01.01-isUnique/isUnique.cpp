#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution{
public:
    bool isUnique(string s){
        vector<bool> table(26, false);
        for (char c : s){
            if (table[c - 'a'])
                return false;
            table[c - 'a'] = true;
        }
        return true;
    }
};