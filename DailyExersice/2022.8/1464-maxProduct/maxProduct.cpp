#include <vector>

using std::vector;

class Solution{
public:
    int maxProduct(vector<int> &nums){
        int len = nums.size(), big = 0, bigger = 0;
        for (int i = 0; i < len; ++i){
            if (nums[i] > bigger){
                big = bigger;
                bigger = nums[i];
            }
            else if (nums[i] > big){
                big = nums[i];
            }
        }
        return (bigger - 1) * (big - 1);
    }
};