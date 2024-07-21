class Solution {
public:
    typedef long long ll;
    ll dp[20010][2];
    ll rec(vector<int>& a,int n,int isEven,int k){
        if(n<0){
            return (isEven==1 ? 0: INT_MIN);
        }
        if(dp[n][isEven]!=-1) return dp[n][isEven];
        
        ll take = (a[n]^k) + rec(a,n-1,isEven^1,k);
        ll notake = a[n] + rec(a,n-1,isEven,k);
        // cout<<n<<" "<<a[n]<<" "<<take<<" "<<notake<<"\n"
        return dp[n][isEven] = max(take,notake);
    }
    long long maximumValueSum(vector<int>& a, int k, vector<vector<int>>& edges) {
        int n = a.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j] = -1;
            }
        }
        // cout<<dp[n-1][0]<<"\n";
        return rec(a,n-1,1,k);
    }
};