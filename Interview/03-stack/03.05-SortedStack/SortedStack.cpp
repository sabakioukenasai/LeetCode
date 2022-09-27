#include <stack>

using std::stack;

// 12ms > 93.69%, 11.6MB > 92.23%
class SortedStack {
private:
    stack<int> _stack;
    stack<int> _swap;

public:
    // do nothing
    SortedStack() { }
    
    void push(int val) {
        while (!_swap.empty() && val < _swap.top())
        {
            _stack.push(_swap.top());
            _swap.pop();
        }
        while(!_stack.empty() && val > _stack.top()){
            _swap.push(_stack.top());
            _stack.pop();
        }
        _stack.push(val);
    }
    
    void pop() {
        while (!_swap.empty())
        {
            _stack.push(_swap.top());
            _swap.pop();
        }
        if (!_stack.empty())
            _stack.pop();
    }
    
    int peek() {
        while (!_swap.empty())
        {
            _stack.push(_swap.top());
            _swap.pop();
        }
        if (_stack.empty())
            return -1;
        else
            return _stack.top();
    }
    
    bool isEmpty() {
        return _stack.empty() && _swap.empty();
    }
};