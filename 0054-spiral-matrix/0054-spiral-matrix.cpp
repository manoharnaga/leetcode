class Solution {
public:
    vector<vector<int>> dir;
    vector<int> ans;
    int check(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        return 1;
    }
    void rec(vector<vector<int>>& mat,int i,int j,int n,int m,int d){
        if(!check(i,j,n,m)) return;
        if(mat[i][j]==-101) return;
        ans.push_back(mat[i][j]);
        mat[i][j] = -101;
        // if(i==(n/2) && j==(m/2)) return;
        if(!check(i+dir[d][0],j+dir[d][1],n,m)){
            d = (d+1)%4;
        }
        else if(mat[i+dir[d][0]][j+dir[d][1]]==-101){
            d = (d+1)%4;
            // if(!check(i+dir[d][0],j+dir[d][1],n,m)){
            //     return;
            // }
        }
        rec(mat,i+dir[d][0],j+dir[d][1],n,m,d);
    }
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        ans.resize(0);
        dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int n = mat.size();
        int m = mat[0].size();
        rec(mat,0,0,n,m,0);
        return ans;
    }
};