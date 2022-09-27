#include <string>
#include <vector>

using std::string;
using std::vector;

// 36ms > 72.09%, 11.1MB > 69.65%
class Solution{
public:
    int uniqueLetterString(string s) {
        int result = 0;                                 // 记录结果
        const int length = s.size();                    // 字符串的长度
        vector<int> left(26, -1), mid(26, -1), last(26, length);

        for (int i = 0; i < length; ++i) {
            int cidx = s[i] - 'A';
            if (mid[cidx] != -1) {
                result += (mid[cidx] - left[cidx]) * (i - mid[cidx]);
                left[cidx] = mid[cidx];
            }
            mid[cidx] = i;
        }
        for (int i = 0; i < 26; ++i)
            result += (length - mid[i]) * (mid[i] - left[i]);
        return result;
    }
};