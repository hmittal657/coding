// https://leetcode.com/problems/min-stack

class MinStack {
public:

    MinStack() {
        while (!st.empty()) {
            st.pop();
            mini.pop();
        }
    }
    
    void push(int val) {
        st.push(val);
        if (mini.empty()) {
            mini.push(val);
        } else {
            if (val > mini.top()) {
                mini.push(mini.top());
            } else {
                mini.push(val);
            }
        }

    }
    
    void pop() {
        st.pop();
        mini.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }

private:
    stack<int> st;
    stack<int> mini;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */