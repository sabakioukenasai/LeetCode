#include <vector>
#include <algorithm>
#include <unordered_map>

using std::unordered_map;
using std::vector;

// 4ms > 95.60%, 10.7MB > 88.66%
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqency;
        for (int num : nums)
            ++freqency[num];
        std::sort(nums.begin(), nums.end(), [&freqency](int a, int b) -> bool
                  { return freqency[a] < freqency[b] || a > b; });
        return nums;
    }
};