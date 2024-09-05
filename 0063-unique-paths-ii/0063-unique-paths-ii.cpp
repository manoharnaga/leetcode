class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& dp) {
        int n = dp.size();
        int m = dp[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(dp[i][j]) dp[i][j]=-1;
        
        if(dp[0][0]!=-1) dp[0][0] = 1;

        for(int i=1;i<n;i++){
            if(dp[i][0]==-1) continue;
            if(dp[i-1][0]!=-1) dp[i][0] = dp[i-1][0];
            else               dp[i][0] = -1;
        }
        for(int j=1;j<m;j++){
            if(dp[0][j]==-1) continue;
            if(dp[0][j-1]!=-1) dp[0][j] = dp[0][j-1];
            else               dp[0][j] = -1;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if((dp[i-1][j]==-1 && dp[i][j-1]==-1) || dp[i][j]==-1){
                    dp[i][j]=-1;
                    continue;
                }
                dp[i][j] += max(dp[i-1][j],0);
                dp[i][j] += max(dp[i][j-1],0);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        return max(0,dp[n-1][m-1]);
    }
};