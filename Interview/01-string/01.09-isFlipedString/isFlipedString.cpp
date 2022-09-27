#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution{
public:
    bool isFlipedString(string s1, string s2){
        if (s1.size() != s2.size())
            return false;

        const int lastind = s1.size() - 1;
        vector<int> posiblePos(1, 0);
        for (int i = 1; i <= lastind; ++i){
            if (s2[i - 1] == s1[lastind] && s2[i] == s1[0])
                posiblePos.push_back(i);
        }

        for (int pos : posiblePos){
            if (checkFlipedPosition(s1, s2, lastind, pos))
                return true;
        }
        return false;
    }

private:
    bool checkFlipedPosition(string& s1, string& s2, int lastind, int pos){
        int j = 0;
        for (int i = pos; i <= lastind; ++i){
            if (s2[i] != s1[j])
                return false;
            ++j;
        }
        int i = 0;
        for (; j <= lastind; ++j){
            if (s2[i] != s1[j])
                return false;
            ++i;
        }
        return true;
    }
};