#include <vector>

using std::vector;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}TreeNode;

class Solution{
private:

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){

        // return construct(nums, 0, nums.size() - 1);

        const size_t len = nums.size();
        TreeNode *root = new TreeNode(nums[0]);
        for (int i = 1; i < len; ++i){
            if (nums[i] > root->val){
                root = new TreeNode(nums[i], root, nullptr);
            }
            else {
                toRight(root, nums[i]);
            }
        }
        return root;
    }

    // 72ms > 83.25%, 38.3MB > 99.71%
    void toRight(TreeNode* parent, int val){
        if (!parent->right)
            parent->right = new TreeNode(val);
        else if (val > parent->right->val){
            parent->right = new TreeNode(val, parent->right, nullptr);
        }
        else{
            toRight(parent->right, val);
        }
    }

    // 88ms > 45.99%, 41.7MB > 43.01%
    TreeNode* construct(vector<int>& nums, int left, int right){
        if (left > right)
            return nullptr;
        if (left == right)
            return new TreeNode(nums[left]);
        int l = left, r = right;
        while (l < r){
            if (nums[l] < nums[r])
                ++l;
            else
                --r;
        }
        return new TreeNode(nums[l],
                            construct(nums, left, l - 1),
                            construct(nums, r + 1, right));
    }
};