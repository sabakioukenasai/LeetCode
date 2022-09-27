#include <vector>

using std::max;
using std::pair;
using std::vector;

typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
} TreeNode;

class Solution{
public:
    int widthOfBinaryTree(TreeNode *root){
        unsigned long long res = 1L;
        vector<pair<TreeNode *, unsigned long long>> array;
        array.emplace_back(root, 1L);
        while(!array.empty()){
            vector<pair<TreeNode *, unsigned long long>> temp;
            for(auto &[node, index] : array){
                if (node->left)
                    temp.emplace_back(node->left, index * 2 + 1);
                if (node->right)
                    temp.emplace_back(node->right, index << 1);
            }
            res = max(res, array.back().second - array[0].second + 1);
            array = move(temp);
        }
        return res;
    }
};