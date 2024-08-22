class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(string s: wordDict) st.insert(s);
        int n = s.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            if(st.find(s.substr(0,i+1))!=st.end()){
                dp[i] = 1;
                continue;
            }
            for(int j=0;j<i;j++){
                if(dp[j] && st.find(s.substr(j+1,(i-j-1+1)))!=st.end()){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};