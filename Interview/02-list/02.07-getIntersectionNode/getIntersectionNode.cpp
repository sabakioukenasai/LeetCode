struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        int lenA = 0, lenB = 0;
        ListNode *pA = headA, *pB = headB;
        while(pA){
            lenA++;
            pA = pA->next;
        }
        while(pB){
            lenB++;
            pB = pB->next;
        }
        pA = headA;
        pB = headB;
        if (lenA > lenB){
            for (int i = 0; i < lenA - lenB; ++i)
                pA = pA->next;
        }
        else {
            for (int i = 0; i < lenB - lenA; ++i)
                pB = pB->next;
        }
        while(pA != pB){
            pA = pA->next;
            pB = pB->next;
        }
        return pB;
    }
};