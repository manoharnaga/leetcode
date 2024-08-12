class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int val: nums) mp[val]++;
        priority_queue<pair<int,int>> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};