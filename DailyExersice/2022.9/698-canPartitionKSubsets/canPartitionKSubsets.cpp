#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution{
private:
    vector<int> v;
    int div;

    bool partition(int idx, int rest) {
        if (idx == v.size())
            return true;
        if (v[idx] > rest)
            return false;
        if (rest == 0)
            rest = div;

        for (int i = idx; i < v.size(); ++i)
        {
            if (v[idx] <= rest)
                if (partition(idx + 1, rest - v[idx]))
                    return true;
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;
        v = vector<int>();
        for (auto i : nums) {
            v.push_back(i);
            sum += i;
        }
        sort(v.begin(), v.end());
        if (sum % k != 0)
            return false;
        div = sum / k;
        return partition(0, k);
    }
};