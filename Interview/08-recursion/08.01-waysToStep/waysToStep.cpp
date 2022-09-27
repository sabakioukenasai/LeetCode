#include <iostream>
#include <vector>
#include <tuple>

using std::tie;
using std::vector;

class Solution {
public:
    int waysToStep(int n) {
        int p = 0, q = 0, r = 0, s = 1;

        while (n -- )
        {
            p = q;
            q = r;
            r = s;
            s = ((p + q) % 1000000007 + r) % 1000000007;
        }

        return s;
    }
};
