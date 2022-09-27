struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 2ms > 83.08%, 16.6MB > 99.43%
class Solution{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == nullptr)
            return nullptr;
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        while(root && (root->val > high || root->val < low)) {
            while(root && root->val > high)
                root = root->left;
            while(root && root->val < low)
                root = root->right;
        }
        return root;
    }
};