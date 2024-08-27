class Solution {
public:
    int rec(string& a,string& b,int n,int m,vector<vector<int>>& dp){
        if(n<0 || m<0) return max(n,m)+1;
        if(dp[n][m]!=-1) return dp[n][m];
        int f1 = (a[n]!=b[m])+rec(a,b,n-1,m-1,dp);
        int f2 = 1+rec(a,b,n-1,m,dp);
        int f3 = 1+rec(a,b,n,m-1,dp);
        return dp[n][m] = min({f1,f2,f3});
    }
    int minDistance(string word1, string word2) {
        int n,m;
        n = word1.size();
        m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(word1,word2,n-1,m-1,dp);
    }
};