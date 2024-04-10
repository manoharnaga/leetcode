class Solution {
public:
    typedef long long ll;
    #define MOD 1000000007
    int numTilings(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;
        vector<ll> dp(n+1,0);
        dp[0]=1;dp[1]=1;dp[2]=2;
        dp[3]=5;
        for(ll i=4;i<=n;i++){
            dp[i] = 2*dp[i-1];
            dp[i] %= MOD;
            dp[i] += dp[i-3];
            dp[i] %= MOD;
        }
        return dp[n];
        
    }
};