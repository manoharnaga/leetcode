class Solution {
public:
    bool rec(vector<int>& a,int n,int s1,int s2,vector<vector<int>>& dp){
        if(n<0){
            if(s1==s2 && s1>0) return true;
            return false;
        }
        if(dp[s1][n]!=-1) return dp[s1][n];
        bool f1 = rec(a,n-1,s1+a[n],s2,dp);
        bool f2 = rec(a,n-1,s1,s2+a[n],dp);
        dp[s1][n] = dp[s2][n] = f1 || f2;
        return f1 || f2;
    }
    
    bool canPartition(vector<int>& a) {
        int n = a.size();
        int sum = 0;
        for(int val: a) sum+=val;
        vector<vector<int>> dp(sum+1,vector<int>(n,-1));
        return rec(a,n-1,0,0,dp);
    }
};