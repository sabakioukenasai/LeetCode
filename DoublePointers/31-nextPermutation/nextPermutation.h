#ifndef _NEXTPERMUTATION_H_
#define _NEXTPERMUTATION_H_

#include <vector>
using std::vector;

class Solution
{
public:
    void nextPermutation(vector<int> &nums){
        if (nums.size() == 1)
            return;
        int idx = nums.size() - 1, i = idx;
        while (idx > 0 && nums[idx - 1] >= nums[idx])
            --idx;
        if (idx > 0){
            while (nums[idx - 1] >= nums[i])
                --i;
            swap(nums[i], nums[idx - 1]);
        }
        i = nums.size() - 1;
        while(i > idx)
            swap(nums[idx++], nums[i--]);
    }
private:
    void swap(int &a, int &b){
        if (a == b)
            return;
        a ^= b;
        b ^= a;
        a ^= b;
    }
};

#endif