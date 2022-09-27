#include <vector>
#include <algorithm>

using std::swap;
using std::vector;

class Solution{
public:
    vector<int> missingTwo(vector<int> &nums) {
        nums.push_back(-1);
        nums.push_back(-1);

        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            while(nums[i] != i + 1 && nums[i] != -1)
                swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == -1)
                ans.push_back(i + 1);

        return ans;
    }
};