#include <vector>
#include <string>

using std::vector;
using std::string;

// 4ms > 89.01%, 10MB > 77.31%
class Solution{
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for (string& s : logs) {
            if (s == "../")
                cnt = cnt > 0 ? cnt - 1 : 0;
            else if (s != "./")
                ++cnt;
        }
        return cnt;
    }
};