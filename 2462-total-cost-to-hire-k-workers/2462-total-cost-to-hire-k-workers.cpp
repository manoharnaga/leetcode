class Solution {
public:
    typedef long long ll;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<ll,vector<ll>,greater<ll>> pq1,pq2;
        int i=0,j = n-1,cnt = 0;
        ll ans = 0;
        while(cnt<k){
            while(pq1.size()<candidates && i<=j) pq1.push(costs[i++]);
            while(pq2.size()<candidates && j>=i) pq2.push(costs[j--]);
            
            ll a = (pq1.empty() ? INT_MAX: pq1.top());
            ll b = (pq2.empty() ? INT_MAX: pq2.top());
            if(a<=b){
                ans += a;
                pq1.pop();
            }
            else{
                ans += b;
                pq2.pop();
            }
            cnt++;
        }
        return ans;
    }
};