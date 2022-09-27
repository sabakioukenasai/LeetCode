#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>

using std::hash;
using std::pair;
using std::tuple;
using std::unordered_map;
using std::unordered_set;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 12ms > 99.55%, 22.9MB > 99.93%
class Solution{
private:
    static constexpr auto tri_hash = [fn = hash<int>()] (const tuple<int, int, int> &o) -> size_t
    {
        auto &&[x, y, z] = o;
        return (fn(x) << 24) ^ (fn(y) << 8) ^ fn(z);
    };

    unordered_map<tuple<int, int, int>, pair<TreeNode *, int>, decltype(tri_hash)> seen{0, tri_hash};
    unordered_set<TreeNode *> repeat;
    int idx = 0;

    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        auto tri = tuple<int, int, int>{node->val, dfs(node->left), dfs(node->right)};
        if (auto it = seen.find(tri); it != seen.end()) {
            repeat.insert(it->second.first);
            return it->second.second;
        }
        else {
            seen[tri] = (node, ++idx);
            return idx;
        }
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        dfs(root);
        return vector<TreeNode *>(repeat);
    }
};