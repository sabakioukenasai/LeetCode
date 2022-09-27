struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 12ms > 92.10%, 13.8MB > 69.24%
class Solution{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return nullptr;
        if (root == p)
            return p;
        if (root == q)
            return q;
        TreeNode *findl = lowestCommonAncestor(root->left, p, q);
        TreeNode *findr = lowestCommonAncestor(root->right, p, q);
        if (findl && findr)
            return root;
        else if (findl)
            return findl;
        else
            return findr;
    }
};