#include <vector>

using std::vector;

class Solution{
private:
    struct LinkNode{
        int val;
        LinkNode *next;
        LinkNode() : val(0), next(nullptr) {}
        LinkNode(int x) : val(x), next(nullptr) {}
        LinkNode(int x, LinkNode *next) : val(x), next(next) {}
    };
    
    int len;
    int K;
    LinkNode *head = new LinkNode();
    LinkNode *rear = nullptr;

    void append(int x) {
        if (len == 0) {
            rear = head->next = new LinkNode(x);
        }
        else {
            LinkNode *p = head;
            while (p != rear && p->next->val > x)
                p = p->next;
            if (p == rear) {
                rear = rear->next = new LinkNode(x);
            }
            else {
                LinkNode *temp = new LinkNode(x, p->next);
                p->next = temp;
            }
        }
        if (len++ == K) {       // 如果满了K个数，则去掉最大的那个
            LinkNode *temp = head->next;
            head->next = temp->next;
            delete temp;
        }
    }

    void yeild(int num, int rest, int lastprod) {
        append(num);
        if (rest == 0)
            return;
        if (lastprod <= 3)
            yeild(num * 3, rest - 1, 3);
        if (lastprod <= 5)
            yeild(num * 5, rest - 1, 5);
        if (lastprod <= 7)
            yeild(num * 7, rest - 1, 7);
    }

public:
    int getKthMagicNumber(int k) {
        K = k;
        len = 0;
        yeild(1, k / 2, 1);

        return head->next->val;
    }
};