#include <unordered_map>
#include <algorithm>
#include <vector>

using std::unordered_map;
using std::sort;
using std::vector;

// 124ms > 95.63%, 8.8MB > 18.58%
class Solution{
public:
    int pileBox(vector<vector<int>> &box) {
        sort(box.begin(), box.end());
        vector<int> height(box.size(), 0);
        // 每个箱子的初始堆叠高度为其本身高度
        for (int i = 0; i < box.size(); ++i) {
            height[i] += box[i][2];
        }

        // 一个箱子只能放在比它序号小的箱子的下面
        for (int i = 1; i < box.size(); ++i) {
            int upper = 0;
            for (int j = 0; j < i; ++j) {
                if (box[j][0] < box[j][0] && box[j][1] < box[j][1] && box[j][2] < box[j][2])
                    upper = std::max(upper, height[j]);
            }
            height[i] += upper;
        }

        int ans = 0;
        for (auto h : height) {
            ans = std::max(ans, h);
        }

        return ans;
    }
};

/**
 * faster 8ms
 * 
using tiii = tuple<int,int,int>;
// 二维树状数组
class BIT{
public:
    vector<vector<int>> tree;
    int nw, nd;
    BIT(int nw, int nd){
        this->nw = nw;
        this->nd = nd;
        tree.resize(nw+1);
        for (int i = 0; i <= nw; i++)
            tree[i].assign(nd+1,0);
    }

    int query(int w, int d){
        int res = 0;
        for (int i = w; i > 0; i -= i&(-i)){
            for (int j = d; j > 0; j -= j&(-j)){
                res = max(res, tree[i][j]);
            }
        }
        return res;
    }

    void update(int w, int d, int v){
        for (int i = w; i <= nw; i += i&(-i)){
            for (int j = d; j <= nd; j += j&(-j)){
                tree[i][j] = max(tree[i][j], v);
            }
        }
    }
};

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        set<int> ws, ds;
        unordered_map<int,int> w2id, d2id;
        vector<tiii> arr;
        for (auto &b : box){
            ws.insert(b[0]);
            ds.insert(b[1]);
            arr.push_back({b[2],-b[0],-b[1]});
        }
        sort(arr.begin(), arr.end());
        int nw = 0;
        for (auto w : ws) w2id[w] = ++nw;
        int nd = 0;
        for (auto d : ds) d2id[d] = ++nd;
        int res = 0;
        BIT T(nw,nd);
        for (auto &[h,w,d] : arr){
            w = -w; d = -d;
            int ph = T.query(w2id[w]-1,d2id[d]-1);
            res = max(res, ph+h);
            T.update(w2id[w],d2id[d],ph+h);
        }
        return res;
    }
};

 * 
*/