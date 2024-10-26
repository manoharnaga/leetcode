class Solution {
public:
    typedef long long ll;
    long long minNumberOfSeconds(int H, vector<int>& w) {
        int n = w.size();
        priority_queue<vector<ll>> pq;
        for(int i=0;i<n;i++) pq.push({-w[i],-1,i});
        ll res = 0;
        for(int i=0;i<H;i++){
            auto p = pq.top();
            pq.pop();
            ll cost = -p[0];
            ll idx = p[2];   
            ll sec = -p[1];
            // cout<<cost<<" "<<idx<<" "<<sec<<"\n";
            res = max(res,cost);
            sec++;
            cost += sec*w[idx];
            pq.push({-cost,-sec,idx});
        }
        return res;
    }
};