class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int m = b.size();
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<n && j<m){
            int u = max(a[i][0],b[j][0]);
            int v = min(a[i][1],b[j][1]);
            if(u<=v) ans.push_back({u,v}); // not my code
            if(a[i][1]<b[j][1]) i++;
            else j++;
        }
        return ans;
    }
};