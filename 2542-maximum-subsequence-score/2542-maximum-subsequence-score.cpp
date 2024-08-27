class Solution {
public:
    typedef long long ll;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<ll> a(n);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({nums2[i],i});
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            a[i] = nums1[v[i].second];
        }
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll sum = 0;
        for(int i=n-1;i>(n-1-k);i--){
            sum += a[i];
            pq.push(a[i]);
        }
        a[n-k] = sum;

        for(int i=(n-1-k);i>=0;i--){
            ll x = a[i];
            ll top = pq.top();
            if(top<x){
                pq.pop();
                pq.push(x);
                sum = sum-top+x;
            }
            a[i] = sum;
        }
        ll ans = 0;
        for(int i=0;i<=(n-k);i++){
            ans = max(ans,v[i].first*a[i]);
        }
        return ans;
    }
};