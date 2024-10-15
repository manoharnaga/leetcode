class Solution {
public:
    int cntg;
    void dfs(int i,int j,int n,int m,vector<vector<int>>& mat){
        if(i<0 || j<0 || i>=n || j>=m || !mat[i][j] || mat[i][j]==2) return;
        mat[i][j] = 2;
        cntg++;
        
        dfs(i+1,j,n,m,mat);
        dfs(i-1,j,n,m,mat);
        dfs(i,j+1,n,m,mat);
        dfs(i,j-1,n,m,mat);
    }
    
    vector<vector<int>> disc,low,par;
    int timer,flag;
    void rec(int i,int j,int pari,int parj,int n,int m,vector<vector<int>>& mat){
        if(flag) return;
        if(i<0 || j<0 || i>=n || j>=m || !mat[i][j] || mat[i][j]==3) return;
        mat[i][j] = 3;
        disc[i][j] = low[i][j] = timer++;
        // cout<<i<<" "<<j<<"k\n";
        
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int c = 0;
        for(auto d: dir){
            int x = i+d[0];
            int y = j+d[1];
            if(x<0 || y<0 || x>=n || y>=m || !mat[x][y]) continue;
            if(x==pari && y==parj) continue;
            if(mat[x][y]==2){
                par[x][y] = i+j;
                rec(x,y,i,j,n,m,mat);
                low[i][j] = min(low[i][j],low[x][y]);
                c++;
                if(par[i][j]==-1 && c>1){
                    // cout<<i<<" "<<j<<"p\n";
                    flag = 1;
                    return;
                }
                if(par[i][j]!=-1 && low[x][y]>=disc[i][j]){
                    cout<<x<<" "<<y<<"child\n";
                    cout<<i<<" "<<j<<"q\n";
                    flag = 1;
                    return;
                }
            }
            else{
                low[i][j] = min(low[i][j],disc[x][y]);
            }
        }
    }
    
    int minDays(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;
        timer = 0;
        disc = low = par = vector<vector<int>> (n,vector<int>(m,-1));
        int ii,jj;
        int f1 = 1;
        cntg = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(f1){
                        ii = i;
                        jj = j;
                        f1 = 0;
                    }
                    
                    dfs(i,j,n,m,mat);
                    // cout<<i<<" "<<j<<"\n";
                    cnt++;
                    if(cnt>1) return 0;
                }
            }
        }
        flag = 0;
        // cout<<ii<<" "<<jj<<"\n";
        rec(ii,jj,-1,-1,n,m,mat);
        cout<<cntg<<"\n";
        if(cntg<1) return 0;
        if(flag || cntg==1) return 1;
        return 2;
    }
};