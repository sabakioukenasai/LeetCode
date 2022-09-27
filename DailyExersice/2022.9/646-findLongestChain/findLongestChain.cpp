#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

// 52ms > 92.13%, 21.8MB > 87.41%
class Solution{
private:
    static bool myCmp (const vector<int> &v1, const vector<int> &v2) {
        return v1[1] < v2[1];
    }
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(), myCmp);
        int cnt = 1, lastNum = pairs[0][1], length = pairs.size();
        for (int i = 1; i < length; ++i) {
            if (pairs[i][0] > lastNum){
                lastNum = pairs[i][1];
                ++cnt;
            }
        }
        return cnt;
    }
};