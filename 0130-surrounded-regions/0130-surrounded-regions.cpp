class Solution {
public:
    void dfs(vector<vector<char>>& a,int i,int j,int n,int m){
        if(i<0 || j<0 || i==n || j==m || a[i][j]=='X' || a[i][j]=='-') return;
        a[i][j] = '-';
        dfs(a,i+1,j,n,m);
        dfs(a,i,j+1,n,m);
        dfs(a,i-1,j,n,m);
        dfs(a,i,j-1,n,m);
    }

    void solve(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        for(int i=0;i<n;i++){
            if(a[i][0]=='O'){
                dfs(a,i,0,n,m);
            }
            if(a[i][m-1]=='O'){
                dfs(a,i,m-1,n,m);
            }
        }
        for(int j=0;j<m;j++){
            if(a[0][j]=='O'){
                dfs(a,0,j,n,m);
            }
            if(a[n-1][j]=='O'){
                dfs(a,n-1,j,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='O') a[i][j]='X';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='-') a[i][j]='O';
            }
        }
    }
};