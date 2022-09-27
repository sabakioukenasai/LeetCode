#include <vector>
#include <stack>

using std::pair;
using std::stack;
using std::vector;

class MinStack {
        // 20ms > 66.61%, 14.7MB > 22.03%
private:
    vector<pair<int, int>> _stack;
    int minIndex;

public:
    /** initialize your data structure here. */
    MinStack() : minIndex(-1) {}
    
    void push(int x) {
        if (minIndex < 0){
            minIndex = 0;
            _stack.emplace_back(x, -1);
        }
        else if (x < _stack[minIndex].first) {
            _stack.emplace_back(x, minIndex);
            minIndex = _stack.size() - 1;
        }
        else{
            _stack.emplace_back(x, -1);
        }
    }
    
    void pop() {
        if (minIndex == _stack.size() - 1)
            minIndex = _stack.back().second;
        _stack.pop_back();
    }
    
    int top() {
        if (!_stack.empty())
            return _stack.back().first;
        else
            throw __cpp_exceptions;
    }
    
    int getMin() {
        if (minIndex >= 0)
            return _stack[minIndex].first;
        else
            throw __cpp_exceptions;
    }
};


class MinStack_2{
    // 16ms > 93.29%, 14,6MB > 68.85%
private:
    stack<int> _stack;
    stack<int> _minStack;
public:
    MinStack_2(){};

    void push(int x) {
        if (_minStack.empty() || x <= _minStack.top())
            _minStack.push(x);
        _stack.push(x);
    }

    int top() {
        return _stack.top();
    }

    void pop() {
        if (!_minStack.empty() && _stack.top() == _minStack.top())
            _minStack.pop();
        _stack.pop();
    }

    int getMin(){
        return _minStack.top();
    }
};