#include <vector>
#include <queue>

using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 4ms > 48.43%, 7,8MB > 83.04%
class Solution{
public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        vector<ListNode *> res;
        vector<TreeNode *> q;

        if (tree == nullptr)
            return res;

        ListNode *head = new ListNode(0), *rear;
        head->next = new ListNode(tree->val);
        q.push_back(tree);

        while(!q.empty()) {
            vector<TreeNode *> temp;
            res.push_back(std::move(head->next));
            rear = head;
            for (TreeNode * node : q) {
                if (node->left){
                    temp.push_back(node->left);
                    rear = rear->next = new ListNode(node->left->val);
                }
                if (node->right){
                    temp.push_back(node->right);
                    rear = rear->next = new ListNode(node->right->val);
                }
            }
            q = std::move(temp);
        }
        return res;
    }
};