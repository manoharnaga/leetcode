class KthLargest {
public:
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int>> minpq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int val: nums){
            maxpq.push(val);
        }
        for(int i=0;i<k && !maxpq.empty();i++){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
    }
    
    int add(int val) {
        if(minpq.size()<K){
            minpq.push(val);
            return minpq.top();
        }
        
        maxpq.push(val);
        val = maxpq.top();
        maxpq.pop();
        
        minpq.push(val);
        val = minpq.top();
        minpq.pop();
        
        return minpq.top();
    }
};



/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */