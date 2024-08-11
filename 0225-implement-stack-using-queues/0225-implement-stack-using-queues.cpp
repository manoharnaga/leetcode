class MyStack {
public:
    deque<int> dq1,dq2;
    MyStack() {
        
    }
    
    void push(int x) {
        dq1.push_back(x);
    }
    
    int pop() {
        while(dq1.size()>1){
            dq2.push_back(dq1.front());
            dq1.pop_front();
        }
        int front = dq1.front();
        dq1.pop_front();
        while(!dq2.empty()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        return front;
    }
    
    int top() {
        while(dq1.size()>1){
            dq2.push_back(dq1.front());
            dq1.pop_front();
        }
        int front = dq1.front();
        dq2.push_back(front);
        dq1.pop_front();
        while(!dq2.empty()){
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        return front;
    }
    
    bool empty() {
        return dq1.empty();
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