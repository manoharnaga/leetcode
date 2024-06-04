class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0;i<(n/2);i++){
            for(int j=i;j<n-i-1;j++){
                int v1=mat[i][j];
                int v2=mat[j][n-1-i];
                int v3=mat[n-1-i][n-1-j];
                int v4=mat[n-1-j][i];
                mat[i][j]=v4;
                mat[j][n-1-i]=v1;
                mat[n-1-i][n-1-j]=v2;
                mat[n-1-j][i]=v3;
            }
        }
    }
};