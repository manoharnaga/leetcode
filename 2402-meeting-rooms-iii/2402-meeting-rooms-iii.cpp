class Solution {
public:
    typedef long long ll;
    int mostBooked(int n, vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        int m = a.size();
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<n;i++) q.push(i);
        
        vector<int> v(m,1);
        
        for(auto x: a){
            int start = x[0],end = x[1];
            while(!pq.empty() && pq.top().first<=start){
                q.push(pq.top().second);
                pq.pop();
            }
            if(!q.empty()){
                v[q.top()]++;
                pq.push({end,q.top()});
                q.pop();
            }
            else{
                v[pq.top().second]++;
                ll val = pq.top().first + end-start;
                pq.push({val,pq.top().second});
                pq.pop();
            }
        }
        // for(int val: v) cout<<val<<" ";
        // cout<<"\n";
        int ind = max_element(v.begin(),v.end())-v.begin();
        return ind;
    }
};