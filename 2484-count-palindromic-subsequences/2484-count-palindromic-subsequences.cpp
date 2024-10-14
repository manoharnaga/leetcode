class Solution {
public:
    typedef long long ll;
    ll mod = 1e9+7;
    string s;
    vector<vector<ll>> dp;
    
    int dfs(int i,int j,string& p){
        if(j==p.size()) return 1;
        if(i==s.size()) return (j==p.size());
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        ll res = dfs(i+1,j,p);
        if(p[j]=='*' || s[i]==p[j]){
            res = (res+dfs(i+1,j+1,p))%mod;
        }
        return dp[i][j] = res;
    }
    
    int countPalindromes(string S) {
        s = S;
        int n = s.size();
        ll res = 0;
        for(char i='0';i<='9';i++){
            for(char j='0';j<='9';j++){
                string x({i,j,'*',j,i});
                // cout<<x<<"\n";
                // find no. of common subsequences btw x,S
                dp = vector<vector<ll>> (n,vector<ll>(5,-1));
                res = (res+max(dfs(0,0,x),0))%mod;
            }
        }
        return res;
    }
};