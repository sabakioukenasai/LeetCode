#ifndef LEETCODE_SORTCOLORS_H
#define LEETCODE_SORTCOLORS_H

#include <vector>
using std::vector;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        if (nums.size() == 2 && nums[0] > nums[1])
            swap(nums[0], nums[1]);
        if (nums.size() < 3)
            return;

        int left = 0, right = nums.size() - 1;
        for (int i = 0; i <= right;){
            if (nums[i] == 2)
                swap(nums[i], nums[right--]);
            if (nums[i] == 0)
                swap(nums[i++], nums[left++]);
            if (nums[i] == 1)
                ++i;
        }
    }
private:
    void swap(int &a, int &b)
    {
        if (a == b)
            return;
        a ^= b;
        b ^= a;
        a ^= b;
    }
};

#endif