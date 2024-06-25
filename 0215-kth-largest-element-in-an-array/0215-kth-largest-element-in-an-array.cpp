class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int val: nums) pq.push(val);
        k--;
        while(k>0){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};