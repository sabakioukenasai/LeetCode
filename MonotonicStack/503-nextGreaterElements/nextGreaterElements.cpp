#include<iostream>
#include<assert.h>
#include<stack>
#include<vector>

using std::cout;
using std::endl;
using std::stack;
using std::vector;


class Solution{
public:
    vector<int> nextGreaterElements(vector<int> &num){
        if (num.size() == 0)
            return vector<int>(0);

        vector<int> res(num.size(), -1);
        stack<int> ind;       // 分别压入下标和数字
        size_t len = num.size(), maxind = 0;

        for (int i = 0; i < len; ++i){
            int cnum = num[i];
            if (cnum > num[maxind])
                maxind = i;

            while(!ind.empty() && cnum > num[ind.top()]){
                res[ind.top()] = cnum;
                ind.pop();
            }
            ind.push(i);
        }
        
        for (int i = 0; i <= maxind; ++i){
            int cnum = num[i];
            while(!ind.empty() && cnum > num[ind.top()]){
                res[ind.top()] = cnum;
                ind.pop();
            }
        }
        return res;
    }
};

int main(){
    cout << "Start" << endl;

    Solution S;

    // 空vector对象
    vector<int> v1 = {};
    assert(S.nextGreaterElements(v1) == v1);

    // 只有一个元素的vector
    vector<int> v2 = {1}, v2_ans = {-1};
    assert(S.nextGreaterElements(v2) == v2_ans);

    // 所有元素相同的vector
    vector<int> v3 = {3, 3, 3, 3}, v3_ans = {-1, -1, -1, -1};
    assert(S.nextGreaterElements(v3) == v3_ans);

    // 倒序排列vector
    vector<int> v4 = {4, 3, 2, 1}, v4_ans = {-1, 4, 4, 4};
    assert(S.nextGreaterElements(v4) == v4_ans);

    // 乱序排列vector
    vector<int> v5 = {7, 0, 2, 4, 4, 3, 5, 1}, v5_ans = {-1, 2, 4, 5, 5, 5, 7, 7};
    assert(S.nextGreaterElements(v5) == v5_ans);

    cout << "Finished" << endl;
}