#include <vector>

using std::vector;

class Solution{
public:
    vector<int> shuffle(vector<int> &nums, int n){
        vector<int> res(2 * n, 0);
        for (int i = 0; i < n; ++i){
            res[i << 1] = nums[i];
            res[(i << 1) + 1] = nums[n + i];
        }
        return res;
    }
};