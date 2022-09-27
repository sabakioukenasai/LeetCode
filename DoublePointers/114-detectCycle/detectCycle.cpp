struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle (ListNode *head)
    {
        ListNode *f = head, *b = head;
        while (f)
        {
            b = b->next;
            f = f->next;
            if (f)
            {
                f = f->next;
                if (b == f)
                    break;
            }
        }
        if (f == nullptr)
            return nullptr;
        while (head != f)
        {
            head = head->next;
            f = f->next;
        }
        return f;
    }
};

/**
 * fastest version
 *
 *  ListNode *detectCycle(ListNode *head)
 *  {
 *      while(head)
 *      {
 *          if (head->next <= head) return head->next;
 *          else        head = head->next;
 *      }
 *  }
 */
