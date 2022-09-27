#include <vector>

using std::vector;

// 0ms > 100%, 6.9MB > 64.72%
class Solution{
private:
    vector<vector<int>> sets;
    vector<int> subset;

    void dfs(vector<int>& nums, int begin, int end) {
        if (begin == end)
            return;
        for (int i = begin; i < end; ++i) {
            subset.push_back(nums[i]);
            sets.push_back(subset);
            dfs(nums, i + 1, end);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sets = {{}};
        dfs(nums, 0, nums.size());
        return sets;
    }
};
/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for(int num : nums){
            for(int i = 0,j = ans.size();i<j;i++){
                vector<int>tmp(ans[i]);
                tmp.push_back(num);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
*/