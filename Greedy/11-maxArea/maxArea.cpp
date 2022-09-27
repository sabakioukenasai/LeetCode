#include <vector>
using std::max;
using std::min;
using std::vector;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1, ans = 0;
        while (left < right)
        {
            int depth = height[left] < height[right] ? height[left++] : height[right--];
            ans = max(ans, depth * (right - left + 1));
        }
        return ans;
    }
};