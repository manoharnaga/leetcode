class Solution {
public:

    int rec(string& s,int start,int ind,int n,set<string>& st,vector<vector<int>>& dp){
        if(ind==n){
            return (st.find(s.substr(start,ind-start))!=st.end());
        }

        if(dp[start][ind]!=-1)  return dp[start][ind];

        int take = rec(s,start,ind+1,n,st,dp);
        int notake = 0;

        if(st.find(s.substr(start,ind-start))!=st.end()){
            notake = rec(s,ind,ind+1,n,st,dp);
        }
        return dp[start][ind] = take || notake;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(string s: wordDict) st.insert(s);
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return rec(s,0,1,n,st,dp);
    }
};