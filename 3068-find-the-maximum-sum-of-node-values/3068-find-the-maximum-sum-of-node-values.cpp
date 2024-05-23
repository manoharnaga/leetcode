class Solution {
public:
    typedef long long ll;
    ll dp[20010][2];
    ll rec(vector<int>& a,int isEven,int idx,int k){
        if(idx == a.size()){
            return (isEven==1 ? 0 : INT_MIN);
        }
        if(dp[idx][isEven]!=-1) return dp[idx][isEven];
        
        ll notake = a[idx]+rec(a,isEven,idx+1,k);
        ll take = (a[idx]^k) + rec(a,isEven^1,idx+1,k);
        return dp[idx][isEven] = max(notake,take);
    }
    long long maximumValueSum(vector<int>& a, int k, vector<vector<int>>& edges) {
        int n = a.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++)
                dp[i][j] = -1;
        }
        ll ans = rec(a,1,0,k);
        return ans;
    }
};