#include<iostream>
#include<queue>
using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode, *TreeNode*;

class Solution {
public:

    void preInorder(TreeNode* root, queue<TreeNode*> &Q) {
        if (root == nullptr)
            return;
        Q.push(root);
        preInorder(root->left, Q);
        preInorder(root->right, Q);
    }

    void flatten(TreeNode* root) {
        queue<TreeNode*> Q;
        preInorder(root, Q);
        TreeNode* parent = Q.front();
        Q.pop();
        while(!Q.empty()){
            TreeNode* child = Q.front();
            Q.pop();
            parent->left = nullptr;
            parent->right = child;
            parent = child;
        }
        parent->right = nullptr;
    }
};