class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
                int v1 = mat[i][j];
                int v2 = mat[j][n-i-1];
                int v3 = mat[n-i-1][n-j-1];
                int v4 = mat[n-j-1][i];
                mat[i][j] = v4;
                mat[j][n-i-1] = v1;
                mat[n-i-1][n-j-1] = v2;
                mat[n-j-1][i] = v3;
            }
        }
    }
};