class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> v;
        int i=0,j=0;
        while(i<n && j<m){
            if(max(a[i][0],b[j][0])<=min(a[i][1],b[j][1])){
                v.push_back({max(a[i][0],b[j][0]),min(a[i][1],b[j][1])});
            }
            if(a[i][1]<=b[j][1]) i++;
            else                 j++;
        }
        return v;
    }
};