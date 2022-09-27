#include <vector>
using std::vector;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0, end = nums.size();
        while (i < end)
        {
            while (i < end && nums[i] != val)
                ++i;
            while (i < end && nums[--end] == val)
                ;
            if (i < end)
                nums[i++] = nums[end];
        }
        return i;
    }
};