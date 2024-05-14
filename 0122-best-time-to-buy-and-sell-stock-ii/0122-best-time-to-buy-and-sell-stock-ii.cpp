class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int dp[n],v[n];
        dp[0] = v[0] = 0;
        for(int i=1;i<n;i++){
            dp[i] = v[i] = 0;
            for(int j=0;j<i;j++){
                dp[i] = max(dp[i],v[j]+prices[i]-prices[j]);
            }
            v[i] = max(v[i-1],dp[i]);
        }
        return *max_element(dp,dp+n);
    }
};