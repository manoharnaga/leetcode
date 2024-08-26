class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        
        while(1){
            vector<vector<int>> dp = grid;
            int f = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0 || grid[i][j]==2) continue;
                    if((i+1)<n && grid[i+1][j]==2){
                        dp[i][j] = 2;
                        f = 1;
                    }
                    if((j+1)<m && grid[i][j+1]==2){
                        dp[i][j] = 2;
                        f = 1;
                    }
                    if((i-1)>=0 && grid[i-1][j]==2){
                        dp[i][j] = 2;
                        f = 1;
                    }
                    if((j-1)>=0 && grid[i][j-1]==2){
                        dp[i][j] = 2;
                        f = 1;
                    }
                }
            }
            if(!f) break;
            cnt++;
            grid = dp;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return cnt;
    }
};