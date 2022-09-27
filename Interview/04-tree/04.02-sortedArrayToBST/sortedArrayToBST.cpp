#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 12ms > 96%, 23.7MB > 85.22%
class Solution{
private:
    TreeNode *buildBST(vector<int> &nums, int left, int right){
        if (right == left)
            return nullptr;
        else {
            int mid = (left + right) >> 1;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = buildBST(nums, left, mid);
            root->right = buildBST(nums, mid + 1, right);
            return root;
        }
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return buildBST(nums, 0, nums.size());
    }
};