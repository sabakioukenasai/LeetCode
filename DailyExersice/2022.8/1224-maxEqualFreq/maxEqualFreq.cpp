#include <unordered_map> 
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::max;
using std::unordered_map;
using std::vector;

class Solution{
public:
    int maxEqualFreq(vector<int> &nums){
        // 120ms > 59%, 43.6MB > 71%
        unordered_map<int, int> numcount, freqcount;
        const size_t length = nums.size();
        int maxfreq = 0, res = 0;

        for (int i = 0; i < length; ++i){
            int number = nums[i];
            if (numcount[number] > 0){
                --freqcount[numcount[number]];
            }
            numcount[number]++;
            ++freqcount[numcount[number]];
            maxfreq = max(maxfreq, numcount[number]);
            if (maxfreq == 1 ||
                (freqcount[maxfreq] * maxfreq  + freqcount[maxfreq - 1] * (maxfreq - 1) == i + 1 && freqcount[maxfreq] == 1) ||
                (freqcount[maxfreq] * maxfreq == i && freqcount[1] == 1))
                res = max(res, i + 1);
        }
        return res;
    }
};