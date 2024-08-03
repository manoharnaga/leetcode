class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        // cout<<n<<" "<<m<<"\n";
        int low = 0,high = n*m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int i = mid/m;
            int j = mid%m;
            // cout<<i<<" "<<j<<"\n";
            if(mat[i][j]>x) high=mid-1;
            else if(mat[i][j]<x) low=mid+1;
            else return true;
        }
        return false;
    }
};