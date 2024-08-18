class Solution {
public:
    int rec(int start,int end,int l,int r,vector<int>& cuts,vector<vector<int>>& dp){
        if(start>=end || l>r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];
        int ans = INT_MAX;
        for(int i=l;i<=r;i++){
            int left = rec(start,cuts[i],l,i-1,cuts,dp);
            int right = rec(cuts[i],end,i+1,r,cuts,dp);
            ans = min(ans,(end-start)+left+right);
        }
        return dp[l][r] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        sort(cuts.begin(),cuts.end());
        return rec(0,n,0,m-1,cuts,dp);
    }
};   