#include <vector>

using std::move;
using std::vector;

// 200ms > 88.04%, 68.2MB > 88.04%
class Solution{
private:
    int findFirst(vector<vector<int>> &graph, int node) {
        int left = 0, right = graph.size() - 1, mid = (left + right) >> 1;
        while(left < right){
            if (graph[mid][0] >= node)
                right = mid;
            else
                left = mid + 1;
            mid = (left + right) >> 1;
        }
        if (graph[right][0] == node)
            return right;
        else
            return graph.size();
    }

public:
    bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start, int target) {

        vector<bool> visited(n, false);     // 某一个节点是否可达
        vector<int> toBeVisited;            // 下一步要访问的节点

        visited[start] = true;              // 初始节点可达
        toBeVisited.push_back(start);       // 下一步从初始节点扩充
        while(!toBeVisited.empty()) {
            vector<int> temp;
            for (int node : toBeVisited) {
                int end = graph.size();
                for (int i = findFirst(graph, node); i < end && graph[i][0] == node; ++i)
                {
                    int targ = graph[i][1];
                    if (!visited[targ]){
                        visited[targ] = true;
                        temp.push_back(targ);
                    }
                }
            }
            toBeVisited = move(temp);
        }
        return visited[target];
    }
};