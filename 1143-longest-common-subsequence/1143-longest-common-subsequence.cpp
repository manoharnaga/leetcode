class Solution {
public:
    int rec(string& text1, string& text2,int n,int m,vector<vector<int>>& dp){
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];

        if(text1[n]==text2[m]){
            return dp[n][m] = 1+rec(text1,text2,n-1,m-1,dp);
        }
        int l = rec(text1,text2,n-1,m,dp);
        int r = rec(text1,text2,n,m-1,dp);
        return dp[n][m]=max(l,r);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(text1,text2,n-1,m-1,dp);
    }
};