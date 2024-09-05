class Solution {
public:
    int rec(string& s1,string& s2,int len,int i,int j,vector<vector<vector<int>>>& dp){
        if(len<1) return 1;
        if(dp[len][i][j]!=-1) return dp[len][i][j];
        if(s1.substr(i,len)==s2.substr(j,len)) return dp[len][i][j] = 1;

        for(int k=1;k<len;k++){
            int f1 = rec(s1,s2,k,i,j,dp) && rec(s1,s2,len-k,i+k,j+k,dp);
            int f2 = rec(s1,s2,k,i,j+len-k,dp) && rec(s1,s2,len-k,i+k,j,dp);
            if(f1 || f2) return dp[len][i][j] = true;
        }
        return dp[len][i][j] = false;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector dp(n+1,vector<vector<int>>(n,vector<int>(n,-1)));
        return rec(s1,s2,n,0,0,dp);
    }
};