#include <algorithm>
#include <map>
#include <string>
#include <tuple>
#include <unordered_set>
#include <queue>
#include <vector>

using std::greater;
using std::map;
using std::priority_queue;
using std::string;
using std::tuple;
using std::vector;

class Solution {
public:
    int minSwap(const string &s1, const string &s2, const int &pos) {
        int tot = 0;
        for (int i = pos; i < s1.size(); i++) {
            tot += s1[i] != s2[i];
        }
        return (tot + 1) / 2;
    }

    int kSimilarity(string s1, string s2) {
        typedef tuple<int, int, int, string> State;
        int n = s1.size();
        priority_queue<State, vector<State>, greater<State>> pq;
        unordered_set<string> visit;
        pq.emplace(0, 0, 0, s1);
        visit.emplace(s1);
        while (!pq.empty()) {
            auto [_, cost, pos, cur] = pq.top();
            pq.pop();
            if (cur == s2) {
                return cost;
            }
            while (pos < n && cur[pos] == s2[pos]) {
                pos++;
            }
            for (int j = pos + 1; j < n; j++) {
                if (s2[j] == cur[j]) {
                    continue;
                }
                if (s2[pos] == cur[j]) {
                    swap(cur[pos], cur[j]);
                    if (!visit.count(cur)) {
                        visit.emplace(cur);
                        pq.emplace(cost + 1 + minSwap(s2, cur, pos + 1), cost + 1, pos + 1, cur);
                    }
                    swap(cur[pos], cur[j]);
                }
            }
        } 
        return 0;
    }
};