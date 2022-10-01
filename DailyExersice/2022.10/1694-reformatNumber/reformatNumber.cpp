#include <string>

using std::string;

class Solution{
public:
    string reformatNumber(string number) {
        int len = number.length();
        for (int i = 0; i < len;) {
            if (number[i] == ' ' || number[i] == '-') {
                number.erase(number.begin() + i);
                --len;
            }
            else {
                ++i;
            }
        }

        int p = -1;
        while(len > 4) {
            p += 4;
            len -= 3;
            number.insert(number.begin() + p, '-');
        }

        switch(len) {
            case 4:
                p += 3;
                number.insert(number.begin() + p, '-' );
                break;
            default:
                break;
        }
        return number;
    }
};