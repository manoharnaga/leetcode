class Solution {
public:
    map<pair<string,int>,int> dp;

    int rec(string& s,string x,int ind,int n,set<string>& st){
        if(ind==n){
            return (st.find(x)!=st.end());
        }
        if(dp.find({x,ind})!=dp.end())  return dp[{x,ind}];

        x+=s[ind];
        int take = rec(s,x,ind+1,n,st);
        x.pop_back();
        int notake = 0;
        if(st.find(x)!=st.end()){
            string tempx = x;
            x = "";
            x += s[ind];
            notake = rec(s,x,ind+1,n,st);
            x = tempx;
        }
        return dp[{x,ind}] = take || notake;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.clear();
        set<string> st;
        for(string s: wordDict) st.insert(s);
        int n = s.size();
        string x="";
        x+=s[0];
        return rec(s,x,1,n,st);
    }
};