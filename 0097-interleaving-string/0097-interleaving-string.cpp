class Solution {
public:
    int n,m;
    int rec(string& s1,string& s2,string& s3,int i,int j,int k,vector<vector<int>>& dp){
        if(i==n && j==m){
            return 1;
        }
        if(i==n) return s2.substr(j)==s3.substr(k);
        if(j==m) return s1.substr(i)==s3.substr(k);

        if(dp[i][j]!=-1) return dp[i][j];
        
        int f1 = (s1[i]==s3[k]) && rec(s1,s2,s3,i+1,j,k+1,dp);
        int f2 = (s2[j]==s3[k]) && rec(s1,s2,s3,i,j+1,k+1,dp);
        // cout<<f1<<" "<<f2<<" "<<i<<" "
        return dp[i][j] = f1 || f2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        if((n+m)!=s3.size()) return false;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(s1,s2,s3,0,0,0,dp);
    }
};