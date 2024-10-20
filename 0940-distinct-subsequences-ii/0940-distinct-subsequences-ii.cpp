class Solution {
public:
    int distinctSubseqII(string s) {
        const int N = s.length();
        const int MOD = 1e9 + 7;
        
        vector<int> dp(N);
        dp[0] = 2;
        vector<int> last(26, -1);
        last[s[0]-'a'] = 0;
        
        // cout<<0<<" "<<-1<<" "<<dp[0]<<"\n";
        for(int i = 1; i < N; i++){
            int x = s[i] - 'a';
            dp[i] = dp[i-1] * 2 % MOD;
            if(last[x] >= 0) // if this is the first occurence of ch
                if(last[x]>0)
                    dp[i] -= dp[last[x]-1];
                else
                    dp[i]--; // empty string
            
            // cout<<i<<" "<<last[x]-1<<" "<<dp[i]<<"\n";
            
            dp[i] %= MOD;
            last[x] = i;
        }
        dp[N-1]--;
        if(dp[N-1] < 0) dp[N-1] += MOD;
        return dp[N-1];
    }
};