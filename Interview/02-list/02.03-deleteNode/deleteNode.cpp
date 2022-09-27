#include <cstdlib>

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
} ListNode;

class Solution{
public:
    void deleteNode(ListNode *node){
        node->val = node->next->val;
        ListNode *temp = node->next;
        node->next = temp->next;
        free(temp);
    }
};