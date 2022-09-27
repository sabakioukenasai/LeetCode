#include <vector>
#include <queue>
#include <numeric>

using std::vector;
using std::priority_queue;
using std::iota;

// 44ms > 22.34%, 19.6MB > 93.62%
class Solution{
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<int> h(n, 0);

        // 按照权重将所有员工降序排列
        iota(h.begin(), h.end(), 0);
        sort(h.begin(), h.end(), [&](int a, int b) -> bool {
            return quality[a] * wage[b] > quality[b] * wage[a];
        });

        double result = 1E9;
        int qsum = 0;                   // quality 的总和
        priority_queue<int, vector<int>, std::less<int>> pq;  // 优先级队列
        for (int i = 0; i < k - 1; ++i) {
            int qua = quality[h[i]];
            pq.push(qua);
            qsum += qua;
        }
        for (int i = k - 1; i < n; ++i) {
            int qua = quality[h[i]];
            pq.push(qua);
            qsum += qua;
            result = std::min(result, qsum * ((double) wage[h[i]] / qua));

            qsum -= pq.top();
            pq.pop();
        }
        return result;
    }
};