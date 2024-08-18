class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(string x: wordDict) st.insert(x);
        int n = s.size();
        vector<int> dp(n);

        for(int i=0;i<n;i++){
            if(st.find(s.substr(0,i+1))!=st.end()){
                dp[i] = true;
                continue;
            }
            for(int j=0;j<i;j++){
                if(dp[j] && st.find(s.substr(j+1,i-j))!=st.end()){
                    dp[i] = true;
                    break;
                }
            }   
        }
        return dp[n-1];
    }
};