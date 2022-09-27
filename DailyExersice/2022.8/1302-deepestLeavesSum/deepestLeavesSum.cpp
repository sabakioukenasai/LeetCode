#include <iostream>
#include <stack>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::stack;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;

class Solution{
public:
    int deepestLeavesSum(TreeNode* root){
        // 使用深度优先搜索，100ms，58.4MB
        // if (root == nullptr)
        //     return 0;

        // int deepest = 0, nowdepth = 0, sum = 0;
        // stack<TreeNode*> nodestack;
        // stack<int> depthstack;
        // nodestack.push(root);
        // depthstack.push(nowdepth);

        // while(!nodestack.empty()){
        //     TreeNode *thisnode = nodestack.top();
        //     nowdepth = depthstack.top();
        //     nodestack.pop();
        //     depthstack.pop();

        //     if (nowdepth > deepest){
        //         deepest = nowdepth;
        //         sum = thisnode->val;
        //     }
        //     else if (nowdepth == deepest){
        //         sum += thisnode->val;
        //     }

        //     if (thisnode->left){
        //         nodestack.push(thisnode->left);
        //         depthstack.push(nowdepth + 1);
        //     }

        //     if (thisnode->right){
        //         nodestack.push(thisnode->right);
        //         depthstack.push(nowdepth + 1);
        //     }
        // }
        // return sum;

        // 使用层序遍历 76ms, 60.4MB

        if (root == nullptr)
            return 0;

        queue<TreeNode *> nodequeue;
        nodequeue.push(root);
        int sum = 0;
        while(!nodequeue.empty()){
            sum = 0;
            int levelsize = nodequeue.size();
            for (int i = 0; i < levelsize; ++i){
                TreeNode *thisnode = nodequeue.front();
                nodequeue.pop();

                sum += thisnode->val;
                if (thisnode->left) nodequeue.emplace(thisnode->left);
                if (thisnode->right) nodequeue.emplace(thisnode->right);
            }
        }
        return sum;
    }
};