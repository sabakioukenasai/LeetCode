#include <vector>
#include <algorithm>

using namespace std;

// 28ms > 82.82%, 18.9MB > 88.17%
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
private:
    bool contain(vector<int> &nums, int item) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == item)
                return true;
            else if (nums[mid] < item)
                left = mid + 1;
            else
                right = mid;
        }
        return false;
    }

public:
    int numComponents(ListNode* head, vector<int>& nums) {
        if (head == nullptr)
            return 0;

        sort(nums.begin(), nums.end());
        int cnt = 0;
        bool seen = false;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            if (seen) {
                if (!contain(nums, p->val))
                    seen = false;
            }
            else {
                if (contain(nums, p->val)) {
                    seen = true;
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};