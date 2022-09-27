struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    // 4ms > 98.30%, 7.4MB > 67.90%
    ListNode *detectCycle(ListNode *head){
        ListNode *p = head, *pp = head;
        while(pp){
            p = p->next;
            pp = pp->next;
            if (pp)
                pp = pp->next;
            if (p == pp)
                break;
        }
        if (pp == nullptr)
            return nullptr;
        p = head;
        while(p != pp){
            p = p->next;
            pp = pp->next;
        }
        return p;
    }
};