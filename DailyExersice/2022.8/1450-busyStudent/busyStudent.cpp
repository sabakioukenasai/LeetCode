#include <vector>

using std::vector;

class Solution{
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime){
        const size_t len = startTime.size();
        int res = 0;
        for (int i = 0; i < len; ++i){
            if (startTime[i] <= queryTime && endTime[i] >= queryTime)
                ++res;
        }
        return res;
    }
};