

typedef struct  ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
} ListNode;

class Solution{
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        // 16ms > 96.07%, 69.4MB > 58.75%
        int sum = l1->val + l2->val, carry = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* head = new ListNode(sum % 10, nullptr);
        ListNode* rear = head; // 定义求和后的列表和列表的尾部

        while(l1 && l2){
            rear = rear->next = new ListNode();
            sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            carry = sum / 10;
            rear->val = sum % 10;
        }
        
        while (carry && l1)
        {
            rear = rear->next = new ListNode();
            sum = carry + l1->val;
            l1 = l1->next;
            carry = sum / 10;
            rear->val = sum % 10;
        }
        while (carry && l2)
        {
            rear = rear->next = new ListNode();
            sum = carry + l2->val;
            l2 = l2->next;
            carry = sum / 10;
            rear->val = sum % 10;
        }

        if (l1){
            rear->next = l1;
        }
        else if (l2){
            rear->next = l2;
        }
        else if (carry)
        {
            rear->next = new ListNode(1, nullptr);
        }
        
        return head;
    }
};
