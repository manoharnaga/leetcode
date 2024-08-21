class Solution {
public:
    int n,m;
    int type,color;
    vector<vector<int>> vist;
    void rec(vector<vector<int>>& a, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || vist[i][j] || a[i][j]!=type) return;
        vist[i][j] = 1;
        a[i][j] = color;

        rec(a,i+1,j);
        rec(a,i,j+1);
        rec(a,i-1,j);
        rec(a,i,j-1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int col) {
        n = image.size();
        m = image[0].size();
        vist = vector<vector<int>> (n,vector<int>(m,0));
        type = image[sr][sc];
        color = col;
        rec(image,sr,sc);
        return image;
    }
};