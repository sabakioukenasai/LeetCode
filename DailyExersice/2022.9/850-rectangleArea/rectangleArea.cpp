#include <vector>
#include <tuple>
#include <algorithm>

using std::get;
using std::sort;
using std::tuple;
using std::vector;

//4ms > 97.85%, 8.2MB > 
class Solution{
public:
    int rectangleArea(vector<vector<int>> &rectangles) {
        int n = rectangles.size();
        vector<int> hbound;
        for (const auto& rect : rectangles) {
            // 下边界
            hbound.push_back(rect[1]);
            // 上边界
            hbound.push_back(rect[3]);
        }
        // 上下边界从小到大排序
        sort(hbound.begin(), hbound.end());
        // 去除重复边界
        hbound.erase(std::unique(hbound.begin(), hbound.end()), hbound.end());
        int m = hbound.size();

        vector<int> seg(m - 1);
        vector<tuple<int, int, int>> sweep;
        for (int i = 0; i < n; ++i) {
            // 左边界
            sweep.emplace_back(rectangles[i][0], i, 1);
            // 右边界
            sweep.emplace_back(rectangles[i][2], i, -1);
        }
        sort(sweep.begin(), sweep.end());

        long long area = 0;
        for (int i = 0; i < sweep.size(); ++i) {
            int j = i;
            while (j + 1 < sweep.size() && get<0>(sweep[j]) == get<0>(sweep[j + 1])) {
                ++j;
            }
            // 如果处理到了最左边，退出循环
            if (j + 1 == sweep.size())
                break;
            
            // 一次性处理掉一批横坐标相同的左右边界
            for (int k = i; k <= j; ++k) {
                auto &&[_, index, diff] = sweep[k];
                int low = rectangles[index][1], high = rectangles[index][3];
                for (int x = 0; x < m - 1; ++x) {
                    if (low <= hbound[x] && hbound[x + 1] <= high)
                        seg[x] += diff;
                }
            }

            int cover = 0;
            for (int k = 0; k < m - 1; ++k) {
                if (seg[k] > 0) {
                    cover += (hbound[k + 1] - hbound[k]);
                }
            }
            area += static_cast<long long>(cover) * (get<0>(sweep[j + 1]) - get<0>(sweep[j]));
            i = j;
        }
        return area % static_cast<int>(1e9 + 7);
    }
};
