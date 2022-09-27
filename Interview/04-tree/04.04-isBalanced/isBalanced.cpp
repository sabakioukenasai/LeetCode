#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using std::pair;

// 8ms > 86.42%, 20.4MB > 47.13%
class Solution{
private:
    bool balanced = true;
    int dfs(TreeNode *node) {
        if (node == nullptr)
            return -1;

        int l = dfs(node->left), r = dfs(node->right);
        if (!balanced)
            return -1;

        if (std::abs(l - r) > 1){
            balanced &= false;
            return -1;
        }
        return std::max(l, r) + 1;
    }
public:
    bool isBalanced(TreeNode *root) {
        balanced = true;
        dfs(root);
        return balanced;
    }
};