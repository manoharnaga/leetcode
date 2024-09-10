class Solution {
public:
    int rec(string& s1,string& s2,int i,int j,int len,vector<vector<vector<int>>>& dp){
        if(len==1) return s1[i]==s2[j];
        
        if(dp[i][j][len]!=-1) return dp[i][j][len];
        
        if(s1.substr(i,len)==s2.substr(j,len)) return 1;
        
        for(int k=1;k<len;k++){
            int f1 = rec(s1,s2,i,j,k,dp) && rec(s1,s2,i+k,j+k,(len-k),dp);
            int f2 = rec(s1,s2,i,j+len-k,k,dp) && rec(s1,s2,i+k,j,(len-k),dp);
            if(f1 || f2) return dp[i][j][len] = true;
        }
        return dp[i][j][len] = false;
    }
    
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector dp(n,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return rec(s1,s2,0,0,n,dp);
    }
};