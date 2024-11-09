class Solution {
public:
    static const int N = 2e4;
    int mod= 1e9+7;
    int cnt[N+1];
    int countSubMultisets(vector<int>& a, int l, int r) {
        int dp[N+1];
        memset(cnt,0,sizeof(cnt));
        memset(dp,0,sizeof(dp));
        
        int n=a.size();
        for(int x:a)cnt[x]++;
        dp[0]=cnt[0]+1;
        for(int i=1;i<=N;i++)
        {
            if(!cnt[i])continue;
            for(int j=N-i;j>=0;j--)
            {
                if(!dp[j])continue;
                for(int k=1;k<=cnt[i];k++)
                {
                    int pos=k*i+j;
                    if(pos>N)break;
                    (dp[pos]+=dp[j]);
                    if(dp[pos]>=mod)dp[pos]-=mod;
                }
            }
        }
        int ans=0;
        for(int i=l;i<=r;i++)
        {
            ans+=dp[i];
            if(ans>=mod)ans-=mod;
        }
        return ans;
    }
};
