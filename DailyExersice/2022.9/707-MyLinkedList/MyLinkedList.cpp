class MyLinkedList {
private:
    struct ListNode {
        int val;
        struct ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode *head;
    int len;

public:
    MyLinkedList() {
        head = new ListNode();
        len = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= len)
            return -1;

        ListNode *p = head->next;
        for (int i = 0; i < index; ++i)
            p = p->next;
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode *p = new ListNode(val, head->next);
        head->next = p;
        ++len;
    }
    
    void addAtTail(int val) {
        ListNode *p = head->next;
        for (; p->next != nullptr; p = p->next)
            ;
        p->next = new ListNode(val);
        ++len;
    }
    
    void addAtIndex(int index, int val) {
        if ( index > len) {
            return;
        }
        else if (index <= 0) {
            addAtHead(val);
        }
        else if (index == len) {
            addAtTail(val);
        } else {
            ListNode *p = head;
            for (int i = 0; i < index; ++i)
                p = p->next;
            ListNode *pp = new ListNode(val, p->next);
            p->next = pp;
            ++len;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len)
            return;
        ListNode *p = head;
        for (int i = 0; i < len; ++i)
            p = p->next;
        ListNode *temp = p->next;
        p->next = temp->next;
        delete temp;
        --len;
        return;
    }
};