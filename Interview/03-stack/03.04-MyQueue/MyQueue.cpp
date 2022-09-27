#include <stack>

using std::stack;

// 0ms > 100%, 6.5MB > 92.09%
class MyQueue{
private:
    stack<int> _stack;
    stack<int> _rstack;

public:
    // 初始化队列结果，do nothing
    MyQueue() { }

    /**
     * Push element x to the back of the queue.
     * */ 
    void push(int x){
        _stack.push(x);
    }

    /**
     * Removes the element from the front of the queue and returns that element.
    */
   	int pop() {
        int val = this->peek();
        _rstack.pop();
        return val;
   }

   /**
    * Get the front element
   */
  	int peek() {
		if (_rstack.empty()){
            while (!_stack.empty())
            {
                _rstack.push(_stack.top());
                _stack.pop();
            }
        }
        return _rstack.top();
	}

	/**
	 * Returns whether the queue is empty
	*/
	bool empty() {
		return _stack.empty() && _rstack.empty();
	}

};