#include <string>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <vector>

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
private:
    static constexpr auto tri_hash = [fn = hash<int>()] (const tuple<int, int, int>&o) -> size_t {
        auto &&[x, y, z] = o;
        return (fn(x) << 24) ^ (fn(y) << 8) ^ fn(z);
    };

    unordered_map<tuple<int, int, int>, int, decltype(tri_hash)> seen{0, tri_hash};
    int idx = 0;

    int dfs(TreeNode *root) {
        if (root == nullptr)
            return 0;

        auto tri = tuple<int, int, int>(root->val, dfs(root->left), dfs(root->right));
        if (auto it = seen.find(tri); it != seen.end()) {
            return it->second;
        }
        else {
            seen[tri] = ++idx;
            return idx;
        }
    }

public:
    bool checkSubTree(TreeNode *t1, TreeNode *t2) {
        int cnt1 = dfs(t1);
        int cnt2 = dfs(t2);
        return cnt1 >= cnt2;
    }
};