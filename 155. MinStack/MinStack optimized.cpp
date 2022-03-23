#include <stack>
using namespace std;





class MinStack {
public:
    stack<int> s;
    stack<int> m;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (m.empty() || val <= m.top()) m.push(val);
        else m.push(m.top());
    }
    
    void pop() {
        s.pop();
        m.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};