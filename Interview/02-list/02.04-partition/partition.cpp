

typedef struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}ListNode;

class Solution{
public:
    ListNode *partition(ListNode *head, int x){
        // 4ms > 87.61%, 9.9MB > 36.94%
        if (head == nullptr)
            return head;
        ListNode *lowwerTail = nullptr, *largerHead = nullptr, *largerTail = nullptr, *newhead = nullptr;
        if (head->val < x){
            newhead = lowwerTail = head;
            while(lowwerTail->next && lowwerTail->next->val < x){
                lowwerTail = lowwerTail->next;
            }
            largerTail = largerHead = lowwerTail->next;
            if (largerHead == nullptr)
                return head;
        }
        else {
            lowwerTail = largerHead = head;
            while(lowwerTail->next && lowwerTail->next->val >= x)
                lowwerTail = lowwerTail->next;
            if (lowwerTail->next == nullptr)
                return head;
            else{
                largerTail = lowwerTail;
                newhead = lowwerTail = lowwerTail->next;
                largerTail->next = newhead->next;
                newhead->next = largerHead;
            }
        }
        while(largerTail->next){
            if (largerTail->next->val >= x){
                largerTail = largerTail->next;
            }
            else {
                lowwerTail = lowwerTail->next = largerTail->next;
                largerTail->next = lowwerTail->next;
            }
        }
        lowwerTail->next = largerHead;
        return newhead;
    }

    ListNode *partition_2(ListNode *head, int x){
        ListNode *small = new ListNode(0);
        ListNode *smallHead = small;
        ListNode *large = new ListNode(0);
        ListNode *largeHead = large;
        ListNode *p = head;
        while(p) {
            if (p->val < x){
                small->next = p;
                small = small->next;
            }
            else {
                large->next = p;
                large = large->next;
            }
            p = p->next;
        }
        small = largeHead->next;
        return smallHead->next;
    }
};