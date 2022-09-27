#include <vector>
#include <algorithm>

using std::vector;

class Solution{
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int size = arr.size(), trimnum = size / 20;
        int sum = 0;
        for (int i = trimnum; i < size - trimnum; ++i)
            sum += arr[i];
        return (double)sum / (size - 2 * trimnum);
    }
};