#include <vector>
#include <stack>

using std::stack;
using std::vector;

class Solution{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped){
        // 4ms > 95.94%, 14.9MB > 57.16%
        int i = 0, j = 0, length = pushed.size();
        stack<int> workStack;
        for (; j < length; ++j){
            if (!workStack.empty() && popped[j] == workStack.top()){
                workStack.pop();
            }
            else
            {
                while(i < length && popped[j] != pushed[i]){
                    workStack.push(pushed[i++]);
                }
                if (i < length && pushed[i] == popped[j])
                    ++i;
                else
                    return false;
            }
        }
        return true;
    }
};