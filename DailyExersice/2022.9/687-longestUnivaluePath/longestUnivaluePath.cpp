struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
    // 104ms > 92.23%, 70MB > 80.62%
{
private:
    int longest = 0;

    // 返回从该节点向下的最长相同路径
    int finder(TreeNode *node, int length) {
        int llen = 0, rlen = 0;
        if (node->left){
            if (node->val == node->left->val)
                llen = finder(node->left, length + 1);
            else
                finder(node->left, 0);
        }
        
        if (node->right){
            if (node->val == node->right->val)
                rlen = finder(node->right, length + 1);
            else
                finder(node->right, 0);
        }
        if (llen + rlen > longest)
            longest = llen + rlen;
        return (llen > rlen ? llen : rlen) + 1;
    }

public:
    
    int longestUnivaluePath(TreeNode *root) {
        if (root == nullptr)
            return 0;
        finder(root, 0);
        return longest;
    }
};

