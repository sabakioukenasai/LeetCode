#include <vector>
#include <stack>

using std::stack;
using std::vector;

// 4ms > 81.96%, 9,6MB > 44.30%
class Solution{
public:
    vector<int> finalPrices(vector<int> &prices){
        const int length = prices.size();
        vector<int> finalprices = prices;
        stack<int> workStack;

        for (int i = 0; i < length; ++i){
            while(!workStack.empty() && prices[i] <= prices[workStack.top()]){
                finalprices[workStack.top()] -= prices[i];
                workStack.pop();
            }
            workStack.push(i);
        }
        return finalprices;
    }
};