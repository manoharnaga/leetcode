class Solution {
public:
    typedef long long ll;
    #define MOD 1000000007
    ll dp[40][1010];
    
    int rec(int n,int k,int x){
        if(x<0 || n<0) return 0ll;
        if(n==0 && x==0) return 1ll;
        if(x==0){
            dp[n][x] = 0;
            return 0;
        }
        if(dp[n][x]!=-1) return dp[n][x];
        ll ans = 0;
        for(int i=1;i<=k;i++){
            ans += rec(n-1,k,x-i);
            ans %= MOD;
        }
        dp[n][x] = ans;
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1ll,sizeof(dp));
        dp[0][0] = 1;
        return rec(n,k,target);
    }
};