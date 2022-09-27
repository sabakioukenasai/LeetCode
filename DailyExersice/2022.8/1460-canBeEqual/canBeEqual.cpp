#include <vector>
#include <cstring>

using std::vector;

class Solution{
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr){
        int len = target.size();
        vector<int> cnt(1001, 0);

        for (int i = 0; i < len; ++i){
            ++cnt[arr[i]];
            --cnt[target[i]];
        }
        for (int i = 1; i <= 1000; ++i){
            if (cnt[i])
                return false;
        }
        return true;
    }
};