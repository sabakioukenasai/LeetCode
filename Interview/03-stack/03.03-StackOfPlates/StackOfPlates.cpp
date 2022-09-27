#include <stack>
#include <vector>

using std::stack;
using std::vector;

class StackOfPlates {
    // 44ms > 79.75%, 27.3MB > 62.16%
private:
    vector<stack<int>> pileStack;
    const int cap;

public:
    StackOfPlates(int cap) : cap(cap >= 0 ? cap : 0) {
        return;
    }
    
    void push(int val) {
        if (cap == 0)
            return;
        if (pileStack.empty() || pileStack.back().size() == cap)
            pileStack.push_back(stack<int>());
        pileStack.back().push(val);
    }
    
    int pop() {
        int top = -1;
        if (!pileStack.empty()) {
            top = pileStack.back().top();
            pileStack.back().pop();
            if(pileStack.back().empty())
                pileStack.pop_back();
        }
        return top;
    }
    
    int popAt(int index) {
        int top = -1;
        if (0 <= index && index < pileStack.size()) {
            top = pileStack[index].top();
            pileStack[index].pop();
            if (pileStack[index].empty())
                pileStack.erase(pileStack.begin() + index);
        }
        return top;
    }
};