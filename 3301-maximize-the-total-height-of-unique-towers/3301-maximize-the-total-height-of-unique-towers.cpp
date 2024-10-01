class Solution {
public:
    typedef long long ll;
    long long maximumTotalSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        ll ans = a[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]>=a[i+1]){
                a[i] = a[i+1]-1;
                if(a[i]==0) return -1;
            }
            // cout<<a[i]<<" ";
            ans += (ll)a[i];
        }
        return ans;
    }
};