#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
        unordered_map<int, int> mp;
        int idx = -1;
        for (auto &vec : pieces) {
            mp[vec[0]] = ++idx;
        }
        
        int i = 0;
        for (; i < arr.size();) {
            vector<int> &vec = pieces[mp[arr[i]]];
            for (int j = 0; j < vec.size(); ++j) {
                if (vec[j] == arr[i]) {
                    ++i;
                }
                else {
                    goto END;
                }
            }
        }
        END:
        return i == arr.size();
    }
};