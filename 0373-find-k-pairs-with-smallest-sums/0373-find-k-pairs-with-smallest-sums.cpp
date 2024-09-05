
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        vector<vector<int>> ans;
        int n = a.size();
        int m = b.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({a[0]+b[0],0,0});
        set<pair<int,int>> st;
        while(ans.size()<k){
            auto it = pq.top();
            // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
            pq.pop();
            if(st.find({it[1],it[2]})!=st.end()) continue;
            int sum = it[0];
            int i = it[1];
            int j = it[2];
            ans.push_back({a[i],b[j]});
            st.insert({i,j});
            if((i+1)<n){
                pq.push({a[i+1]+b[j],i+1,j});
            }
            if((j+1)<m){
                pq.push({a[i]+b[j+1],i,j+1});
            }
        }
        return ans;
    }
};