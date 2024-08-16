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
        sort(coins.begin(),coins.end());
        
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int x=1;x<=amount;x++){
            for(int j=0;j<n;j++){
                if((x-coins[j])>=0 && dp[x-coins[j]]!=INT_MAX){
                    dp[x] = min(dp[x],1+dp[x-coins[j]]);
                }
            }
        }
        return (dp[amount]==INT_MAX ? -1: dp[amount]);
    }
};