struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    // 4ms > 76.08%, 12.9MB > 98.43%
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        TreeNode *blankRoot = new TreeNode(0, nullptr, root);
        placeNode(blankRoot, val);
        return blankRoot->right;
    }

private:
    void placeNode(TreeNode *root, int val) {
        if (root->right){
            if (val > root->right->val){
                root->right = new TreeNode(val, root->right, nullptr);
            }
            else {
                placeNode(root->right, val);
            }
        }
        else {
            root->right = new TreeNode(val);
        }
    }
};