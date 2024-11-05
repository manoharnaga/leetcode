class Solution {
public:
    int dp[101][101];
    int rec(int i,int j,string& s){
        if(i==j) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res = INT_MAX;
        for(int k=0;k<(j-i);k++){
            int l = rec(i,i+k,s);
            int r = rec(i+k+1,j,s);
            res = min(res,l+r);
        }
        return dp[i][j] = res-(s[i]==s[j]);
    }
    
    int strangePrinter(string s) {
        int n = s.size();
        string t;
        char prev = '-';
        for(int i=0;i<n;i++){
            if(prev!=s[i]){
                t+=s[i];
                prev = s[i];
            }
        }
        int cnt = 0;
        int m = t.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,m-1,t);
    }
};