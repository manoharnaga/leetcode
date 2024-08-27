class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> ispal(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(s[i]==s[j] && ((j-i)<2 || ispal[i+1][j-1])){
                    ispal[i][j] = 1;
                }
            }
        }
        vector<int> dp(n,INT_MAX);
        for(int i=0;i<n;i++){
            if(ispal[0][i]){
                dp[i] = 1;
                continue;
            }
            for(int j=0;j<i;j++){
                if(ispal[j+1][i] && dp[j]!=INT_MAX){
                    dp[i] = min(dp[i],1+dp[j]);
                }
            }
        }
        return dp[n-1]-1;
    }
};