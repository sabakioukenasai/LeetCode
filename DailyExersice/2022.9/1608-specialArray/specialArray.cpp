#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

class Solution{
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), std::greater<int>());
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i) {
            if (i < nums[i] && i >= nums[i + 1])
                return i + 1;
        }
        if (nums[size - 1] >= size)
            return size;
        else
            return -1;
    }
};