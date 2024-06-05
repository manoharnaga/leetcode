class Solution {
public:
    int dp[1010][1010];
    int rec(string& x,string& y,int n,int m){
        if(n==0 || m==0) return 0;
        if(x[n-1]==y[m-1]){
            dp[n][m] = 1+rec(x,y,n-1,m-1);
            return dp[n][m];
        }
        if(dp[n][m]!=-1) return dp[n][m];
        return dp[n][m] = max(rec(x,y,n-1,m),rec(x,y,n,m-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        for(int i=0;i<1010;i++)
            for(int j=0;j<1010;j++)
                dp[i][j] = -1;
        return rec(text1,text2,text1.size(),text2.size());
    }
};