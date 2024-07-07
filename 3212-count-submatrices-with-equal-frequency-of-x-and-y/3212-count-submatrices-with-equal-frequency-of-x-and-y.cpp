class Solution {
public:
    int check(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        return 1;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mat[n][m],v[n][m];
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val = 0;
                if(grid[i][j]=='X') val = 1;
                else if(grid[i][j]=='Y') val = -1;
                else val = 0;
                mat[i][j] = val;
                v[i][j] = (grid[i][j]=='X');
                if(i-1>=0 && j-1>=0){
                    mat[i][j] += mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
                    v[i][j] = v[i][j] || v[i-1][j] || v[i][j-1];
                }
                else{
                    if(i-1>=0){
                        mat[i][j]+=mat[i-1][j];
                        v[i][j] = v[i][j] || v[i-1][j];
                    }
                    if(j-1>=0){
                        mat[i][j]+=mat[i][j-1];
                        v[i][j] = v[i][j] || v[i][j-1];
                    }
                }
                if(v[i][j] && mat[i][j]==0) ans++;
                // cout<<mat[i][j]<<" "<<v[i][j]<<" "<<ans<<" "<<i<<" "<<j<<"\n";
            }
        }
        
        return ans;
    }
};