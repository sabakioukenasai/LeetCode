#include <unordered_map>

using std::unordered_map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
private:
    unordered_map<int, int> pref;       // 记录所有前缀和
    int target = 0;

    // curr 表示前缀和
    int dfs(TreeNode *node, int curr) {
        if (node == nullptr)
            return 0;

        int res = 0;
        curr += node->val;
        if (pref.find(curr - target) != pref.end())
            res = pref[curr - target];
            
        ++pref[curr];
        res += dfs(node->left, curr);
        res += dfs(node->right, curr);
        --pref[curr];
        return res;
    }


    public:
        int pathSum(TreeNode *root, int sum)
        {
            pref[0] = 1;
            target = sum;
            return dfs(root, 0); // 根节点的前缀和是0
    }
};