#include <vector>
#include <string>

using std::max;
using std::string;
using std::to_string;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
    vector<vector<string>> printTree(TreeNode *root){
        treeHeight = getHeight(root);
        matrix = vector<vector<string>>(treeHeight + 1, vector<string>((2 << treeHeight) - 1, ""));
        placeNode(root, 0, (1 << treeHeight) - 1);
        return matrix;
    }

    private:    
    int treeHeight = 0;
    vector<vector<string>> matrix;

    int getHeight(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        else if (root->left == nullptr)
            return getHeight(root->right) + 1;
        else if (root->right == nullptr)
            return getHeight(root->left) + 1;
        else
            return max(getHeight(root->right), getHeight(root->left)) + 1;
    }

    void placeNode(TreeNode *node, int row, int col){
        matrix[row][col] = to_string(node->val);
        if (node->left)
            placeNode(node->left, row + 1, col - (1 << (treeHeight - row - 1)));
        if (node->right)
            placeNode(node->right, row + 1, col + (1 << (treeHeight - row - 1)));
    }
};