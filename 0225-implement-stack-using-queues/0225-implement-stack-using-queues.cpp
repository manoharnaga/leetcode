class MyStack {
public:
    deque<int> dq;
    MyStack() {
        
    }
    
    void push(int x) {
        dq.push_back(x);
        int n = dq.size();
        for(int i=0;i<n-1;i++){
            int cur = dq.front();
            dq.pop_front();
            dq.push_back(cur);
        }
    }
    
    int pop() {
        int front = dq.front();
        dq.pop_front();
        return front;
    }
    
    int top() {
        return dq.front();
    }
    
    bool empty() {
        return dq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */