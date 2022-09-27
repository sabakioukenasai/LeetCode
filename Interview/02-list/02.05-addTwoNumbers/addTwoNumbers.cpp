

struct ListNode{
    int val;
    ListNode *next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode *p1 = l1, *p2 = l2;
        ListNode *res = new ListNode();
        ListNode *resHead = res;
        int sum = 0, carry = 0;

        while(p1 && p2){
            sum = p1->val + p2->val + carry;
            carry = sum / 10;
            res = res->next = new ListNode(sum - 10 * carry);
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1){
            if (carry){
                while(p1 && p1->val == 9){
                    res = res->next = new ListNode();
                    p1 = p1->next;
                }
                if (p1){
                    res = res->next = new ListNode(p1->val + 1);
                    p1 = p1->next;
                }
                else{
                    res = res->next = new ListNode(1);
                }
            }
            res->next = p1;
        }
        else if (p2){
            if (carry){
                while(p2 && p2->val == 9) {
                    res = res->next = new ListNode();
                    p2 = p2->next;
                }
                if (p2){
                    res = res->next = new ListNode(p2->val + 1);
                    p2 = p2->next;
                }
                else{
                    res = res->next = new ListNode(1);
                }
            }
            res->next = p2;
        } else if (carry) {
            res->next = new ListNode(1);
        }

        return resHead->next;
    }
};