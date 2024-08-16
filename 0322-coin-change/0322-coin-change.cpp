class Solution {
public:
    int rec(vector<int>& coins,int n,int sum,vector<vector<int>>& dp){
        if(sum==0) return 0;

        if(sum<0 || n<0){
            return INT_MAX;
        }

        if(dp[sum][n]!=-1) return dp[sum][n];

        int l = rec(coins,n,sum-coins[n],dp);
        if(l!=INT_MAX) l++;
        int r = rec(coins,n-1,sum,dp);
        return dp[sum][n] = min(l,r);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));

        int ans = rec(coins,n-1,amount,dp);
        return (ans==INT_MAX ? -1: ans);
    }
};