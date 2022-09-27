#include <string>

using std::string;

class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        for (int i = 0; i < 30; ++i) {
            num *= 2;
            if (num > 1) {
                res.append("1");
                num -= 1;
            }
            else {
                res.append("0");
            }
            if (num == 0)
                return res;
        }
        return "ERROR";
    }
};