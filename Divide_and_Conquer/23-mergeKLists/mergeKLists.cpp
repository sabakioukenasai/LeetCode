#include <vector>
using std::vector;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *p) : val(x), next(p) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *>& lists)
    {
        if (lists.size() == 0)
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        if (lists.size() == 2)
            return mergeTwo(lists[0], lists[1]);

        int len = lists.size();
        while(len > 1)
        {
            int newlen = 0, i = 1;
            for (; i < len; ++++i)
                lists[newlen++] = mergeTwo(lists[i - 1], lists[i]);
            if (i == len)
                lists[newlen++] = lists[len - 1];
            len = newlen;
        }
        return lists[0];
    }
private:
    ListNode *mergeTwo(ListNode *head1, ListNode *head2)
    {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;

        ListNode head, *rear = &head;
        while(head1 && head2)
        {
            if (head1->val < head2->val)
            {
                rear = rear->next = head1;
                head1 = head1->next;
            }
            else
            {
                rear = rear->next = head2;
                head2 = head2->next;
            }
        }
        if (head1)
            rear->next = head1;
        else
            rear->next = head2;
        return head.next;
    }
};