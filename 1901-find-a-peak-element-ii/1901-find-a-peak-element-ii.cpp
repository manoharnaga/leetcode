class Solution {
public:
    
    int getMaxIdx(vector<vector<int>>& mat,int n,int col){
        int idx=0;
        for(int i=0;i<n;i++){
            if(mat[i][col]>mat[idx][col]){
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0,high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int row = getMaxIdx(mat,n,mid);
            int l = (mid>0 ? mat[row][mid-1]: -1);
            int r = (mid<m-1 ? mat[row][mid+1]:-1);
            if(mat[row][mid]>l && mat[row][mid]>r) return {row,mid};
            else if(mat[row][mid]<l) high = mid-1;
            else if(mat[row][mid]<r) low = mid+1;
            else{
                high = mid-1;
            }
        }
        return {-1,-1};
    }
};