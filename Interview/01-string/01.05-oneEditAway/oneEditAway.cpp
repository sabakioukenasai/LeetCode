#include <string>

using std::abs;
using std::min;
using std::string;

class Solution{
public:
    bool oneEditAway(string first, string second){
        const int fsize = first.size(), ssize = second.size();
        if (abs(fsize - ssize) > 1)
            return false;
        int end = min(fsize, ssize), i = 0;
        while (i < end && first[i] == second[i])
            ++i;
        if (i == end)
            return true;

        if (fsize == ssize){
            while (++i < end && first[i] == second[i])
                ;
            if (i == end)
                return true;
        } else if (fsize < ssize){
            while (i < end && first[i] == second[i + 1])
                ++i;
            if (i == end)
                return true;
        } else {
            while (i < end && first[i + 1] == second[i])
                ++i;
            if (i == end)
                return true;
        }
        return false;
    }
};