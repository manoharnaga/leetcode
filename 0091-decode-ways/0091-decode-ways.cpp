class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        map<string,int> v;
        for(int i=1;i<=26;i++){
            v[to_string(i)] = 1;
        }
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            
            int f = 0;
            if(v[s.substr(i-1,1)]){
                // cout<<s.substr(i-1,1)<<"\n";
                dp[i] += dp[i-1];
                f = 1;
            }
            if(i>1 && v[s.substr(i-2,2)]){
                // cout<<s.substr(i-2,2)<<"\n";
                dp[i] += dp[i-2];
                f = 1;
            }
            
            if(!f){
                return 0;
            }
        }
        // for(int val: dp) cout<<val<<" ";
        // cout<<"\n";
        return dp[n];
    }
};