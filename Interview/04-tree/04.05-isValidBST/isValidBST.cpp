#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
private:
    bool dfs(TreeNode *node, long lbound, long rbound) {
        if (node == nullptr)
            return true;
        if (node->val <= lbound || node->val >= rbound)
            return false;
        return dfs(node->left, lbound, node->val) && dfs(node->right, node->val, rbound);
    }

public:
    bool isValidBST(TreeNode *root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};