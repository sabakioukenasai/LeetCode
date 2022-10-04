#include <string>

using std::string;

// 0ms > 100%, 6MB > 20.54%
class Solution{
public:
    bool checkOnesSegment(string s) {
        bool appear = false;
        int segcnt = 0;
        int i = 0;
        while(i < s.size()) {
            if (s[i] == '1') {
                if (!appear)
                    if (++segcnt > 1)
                        break;;
                appear = true;
            }
            else {
                appear = false;
            }
            ++i;
        }
        return segcnt == 1;
    }
};