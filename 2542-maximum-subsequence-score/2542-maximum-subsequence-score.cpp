class Solution {
public:
    typedef long long ll;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<ll,ll>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll sum = 0,ans = 0;
        for(int i=n-1;i>=(n-k);i--){
            sum += v[i].second;
            pq.push(v[i].second);
        }
        ans = max(ans,sum*v[n-k].first);
        for(int i=n-k-1;i>=0;i--){
            ll top = pq.top();
            if(top<v[i].second){
                sum = sum-top+v[i].second;
                pq.pop();
                pq.push(v[i].second);
            }
            ans = max(ans,sum*v[i].first);
        }
        return ans;
    }
};