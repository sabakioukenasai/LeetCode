#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::to_string;
using std::unordered_map;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 24ms > 95.27%, 47.7MB > 47.35%
class Solution {
private:
    unordered_map<string, int> mp;
    vector<TreeNode *> result;

    string selializer(TreeNode *root) {
        if (root == nullptr)
            return "^";

        string str;
        str = to_string(root->val) + "," + selializer(root->left) + "," + selializer(root->right);
        if (mp[str] == 1)
            result.push_back(root);
        ++mp[str];
        return str;
    }

    // 将二叉树序列化，通过使用特殊符号描述空节点唯一确定一个二叉树
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        mp.clear();
        result.clear();
        selializer(root);
        return result;
    }
};