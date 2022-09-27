struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {} 
};

class Solution
{
public:
    int kthToLast(ListNode *head, int k)
    {
        ListNode *f = head, *b = head;
        for (int i = 0; i < k; ++i)
            f = f->next;
        while (f != nullptr)
        {
            f = f->next;
            b = b->next;
        }
        return b->val;
    }
};
