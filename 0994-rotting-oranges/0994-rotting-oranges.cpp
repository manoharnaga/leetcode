class Solution {
public:
    int fcnt,rcnt;
    void rec(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i<0 || j<0 || i==n || j==m || grid[i][j]==0 || grid[i][j]==2) return;
        grid[i][j] = 2;
        fcnt--;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        fcnt = rcnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    rcnt++;
                }
                if(grid[i][j]==1){
                    fcnt++;
                }
            }
        }
        int min = 0;
        vector<vector<int>> grid2;
        while(fcnt){
            int prevfcnt = fcnt;
            grid2 = grid;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==2){
                        rec(grid2,i-1,j,n,m);
                        rec(grid2,i,j-1,n,m);
                        rec(grid2,i+1,j,n,m);
                        rec(grid2,i,j+1,n,m);
                    }
                }
            }
            grid = grid2;
            if(fcnt>=prevfcnt) return -1;
            min++;
        }
        return min;
    }
};