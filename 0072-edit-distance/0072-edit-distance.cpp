class Solution {
public:
    int rec(string& x,string& y,int n,int m,vector<vector<int>>& dp){
        if(n==0) return dp[n][m] = m;
        if(m==0) return dp[n][m] = n;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        int f1 = !(x[n-1]==y[m-1])+rec(x,y,n-1,m-1,dp);
        int f2 = 1+rec(x,y,n-1,m,dp);
        int f3 = 1+rec(x,y,n,m-1,dp);
        return dp[n][m] = min({f1,f2,f3});
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return rec(word1,word2,n,m,dp);
    }
};