class MinStack {
public:
    stack<int> st;
    stack<int> mins;
    
    MinStack() {
    
    }
    
    void push(int val) {
        st.push(val);
        if(st.size() == 1) {
            mins.push(st.top());
        } else {
            mins.push(min(mins.top(), st.top()));            
        }
    }
    
    void pop() {
        mins.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */