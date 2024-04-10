class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // dp[0][0] = 0,dp[i][0] = 0, dp[0][i] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1] = 1+dp[i][j];
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[n][m];
    }
};