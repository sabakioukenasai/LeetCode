#include <assert.h>
#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

class Solution{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        size_t len = temperatures.size();
        vector<int> hotterday(len, 0);
        stack<int> workStack;

        for (int i = 0; i < len; ++i){
            while(!workStack.empty() && temperatures[i] > temperatures[workStack.top()]){
                hotterday[workStack.top()] = i - workStack.top();
                workStack.pop();
            }
            workStack.push(i);
        }

        return hotterday;
    }
};


int main() {
    cout << "Start" << endl;

    Solution S;

    // 空vector对象
    vector<int> v1 = {};
    assert(S.dailyTemperatures(v1) == v1);

    // 只有一个元素的vector
    vector<int> v2 = {1}, v2_ans = {0};
    assert(S.dailyTemperatures(v2) == v2_ans);

    // 所有元素相同的vector
    vector<int> v3 = {3, 3, 3, 3}, v3_ans = {0, 0, 0, 0};
    assert(S.dailyTemperatures(v3) == v3_ans);

    // 倒序排列vector
    vector<int> v4 = {4, 3, 2, 1}, v4_ans = {0, 0, 0, 0};
    assert(S.dailyTemperatures(v4) == v4_ans);

    // 乱序排列vector
    vector<int> v5 = {7, 0, 2, 4, 4, 3, 5, 1}, v5_ans = {0, 1, 1, 3, 2, 1, 0, 0};
    for (int item : S.dailyTemperatures(v5))
        cout << item << ", ";
    cout << endl;
    assert(S.dailyTemperatures(v5) == v5_ans);

    cout << "Finished" << endl;
}