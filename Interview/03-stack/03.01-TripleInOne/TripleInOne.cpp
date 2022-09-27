#include <cstring>

class TripleInOne {
private:
    const int maxSize;
    int *stack_;
    int top[3];

public:
    // 56ms > 83.93%, 32MB > 97.60%
    TripleInOne (int stackSize) : maxSize(stackSize) {
        stack_ = new int[stackSize * 3];
        memset(top, 0, sizeof(top));
    }

    void push(int stackNum, int value){
        if (top[stackNum] == maxSize)
            return;
        else
            stack_[maxSize * stackNum + (top[stackNum]++)] = value;
    }

    int pop(int stackNum){
        if (top[stackNum])
            return stack_[maxSize * stackNum + (--top[stackNum])];
        else
            return -1;
    }

    int peek(int stackNum){
        if (top[stackNum])
            return stack_[maxSize * stackNum + top[stackNum] - 1];
        else
            return -1;
    }

    bool isEmpty(int stackNum){
        return top[stackNum] == 0;
    }

    ~TripleInOne() { delete[] stack_; }
};