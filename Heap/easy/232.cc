// https://leetcode.com/problems/implement-queue-using-stacks/
#include <stack>

class MyQueue {
private:
    std::stack<int> a;
    std::stack<int> b;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        if (b.empty()) {
            while (!a.empty()) {
                b.push(a.top());
                a.pop();
            }
        }
        int res = b.top();
        b.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();
        b.push(res);
        return res;
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
};
