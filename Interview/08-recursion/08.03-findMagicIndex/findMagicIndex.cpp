#include <vector>

using std::vector;

class Solution{
public:
    int findMagicIndex(vector<int> &nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i)
            if (i == nums[i])
                return i;
        return -1;
    }
};