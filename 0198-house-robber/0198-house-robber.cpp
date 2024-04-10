class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i] = a[i];
            for(int j=0;j<i-1;j++){
                dp[i] = max(dp[i],a[i]+dp[j]);
            }
        }
        // for(int val: dp) cout<<val<<" ";
        // cout<<"\n";
        return *max_element(dp.begin(),dp.end());
    }
};