class Solution {
public:
    int maxWidthRamp(vector<int>& b) {
        int n = b.size();
        vector<pair<int,int>> c;
        for(int i=1;i<=n;i++){
            c.push_back({b[i-1],i});
        }
        sort(c.begin(),c.end());
        vector<int> v(n,INT_MIN);
        int ans = 0;
        v[n-1] = c[n-1].second;
        for(int i=n-2;i>=0;i--){
            v[i] = max(v[i+1],c[i].second);
        }
        for(int i=0;i<n-1;i++){
            ans = max(ans,v[i+1]-c[i].second);
        }
        return ans;
    }
};