class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        int minval;
        if(st.empty()) minval = val;
        else minval = min(st.top(),val);
        st.push(val);
        st.push(minval);
    }
    
    void pop() {
        st.pop();
        st.pop();
    }
    
    int top() {
        int minval = st.top();
        st.pop();
        int curval = st.top();
        st.push(minval);
        return curval;
    }
    
    int getMin() {
        return st.top();
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