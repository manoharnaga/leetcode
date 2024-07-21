class Solution {
public:
    typedef long long ll;
    #define MOD 1000000007
    ll dp[100010][2][3];
    ll rec(int n,int abscnt,int latecnt){
        // cout<<"hi\n";
        if(abscnt>1 || latecnt>2) return 0ll;
        if(n<0) return 1ll;
        if(dp[n][abscnt][latecnt]!=-1) return dp[n][abscnt][latecnt];
        
        ll cnt = rec(n-1,abscnt,0);
        cnt += rec(n-1,abscnt+1,0);
        cnt %= MOD;
        cnt += rec(n-1,abscnt,latecnt+1);
        cnt %= MOD;
        // cout<<cnt<<"\n";
        return dp[n][abscnt][latecnt] = cnt;
    }
    
    int checkRecord(int n) {
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return rec(n-1,0,0);
    }
};