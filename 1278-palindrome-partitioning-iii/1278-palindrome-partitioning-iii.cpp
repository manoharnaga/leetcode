class Solution {
public:
    int palindromePartition(string s, int K) {
        int n = s.size();
        vector<vector<int>> pal(n,vector<int>(n,0)),dp(n,vector<int>(K+1,0));
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(i==j){
                    pal[i][j] = 0;
                }
                else if((j-i)==1){
                    if(s[i]!=s[j]) pal[i][j]=1;
                    else           pal[i][j]=0;
                }
                else{
                    if(s[i]==s[j]) pal[i][j] = pal[i+1][j-1];
                    else           pal[i][j] = 1+pal[i+1][j-1];
                }
            }
        }
        for(int i=0;i<n;i++){
            dp[i][1] = pal[0][i];
        }
        for(int k=2;k<=K;k++){
            for(int j=0;j<n;j++){
                dp[j][k] = j+1;
                for(int l=0;l<j;l++){
                    dp[j][k] = min(dp[j][k],dp[l][k-1]+pal[l+1][j]);
                }
            }
        }
        return dp[n-1][K];
    }
};