#include <vector>

using std::vector;

typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

class Solution{
public:
    ListNode *removeDuplicateNodes(ListNode *head){
        vector<bool> appear(20001, false);
        ListNode *res = new ListNode, *rear = res;
        while(head){
            if (!appear[head->val]){
                rear = rear->next = new ListNode(head->val);
                appear[head->val] = true;
            }
            head = head->next;
        }
        return res->next;
    }
};