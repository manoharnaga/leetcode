class MinStack {
public:
    stack<int> st;
    MinStack() {
        st = stack<int>();
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            st.push(val);
        }
        else{
            int top = st.top();
            st.push(val);
            st.push(min(top,val));
        }
    }
    
    void pop() {
        if(st.empty()) return;
        st.pop();
        st.pop();
    }
    
    int top() {
        int minval = st.top();
        st.pop();
        int top = st.top();
        st.push(minval);
        return top;
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