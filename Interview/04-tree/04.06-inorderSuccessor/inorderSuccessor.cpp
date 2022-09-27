struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 28ms >  64.23%, 22.2MB > 96.23%
class Solution{
private:
    bool pfound = false;

    TreeNode *findNextInRightSubtree(TreeNode *&node) {
        TreeNode *p = node;
        while(p->left)
            p = p->left;
        return p;
    }

    TreeNode *dfs(TreeNode *&node, TreeNode *&p) {
        if (node == nullptr)
            return nullptr;
        TreeNode *ans = nullptr;
        if (node->val > p->val && (ans = dfs(node->left, p)) != nullptr)
            return ans;
        if (pfound)
            return node;
        if (p == node) {
            pfound = true;
            return nullptr;
        }
        return dfs(node->right, p);
    }

public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (p->right)
            return findNextInRightSubtree(p->right);
        else
            return dfs(root, p);
    }
};