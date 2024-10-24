class Solution {
public:
    int isham(string& x,string& y){
        if(x.size()==y.size()){
            int cnt = 0;
            for(int i=0;i<x.size();i++){
                cnt+=(x[i]!=y[i]);
                if(cnt>1) return 0;
            }
            return (cnt==1);
        }
        return 0;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& w, vector<int>& g) {
        int n = w.size();
        vector<int> par(n,-1),dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(g[i]!=g[j] && isham(w[i],w[j])){
                    if((1+dp[j])>dp[i]){
                        dp[i] = 1+dp[j];
                        par[i] = j;
                    }
                }
            }
        }
        int idx = max_element(dp.begin(),dp.end())-dp.begin();
        vector<string> res;
        while(par[idx]!=-1){
            res.push_back(w[idx]);
            idx = par[idx];
        }
        res.push_back(w[idx]);
        reverse(res.begin(),res.end());
        return res;
    }
};
