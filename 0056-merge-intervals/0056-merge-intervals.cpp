class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](const auto& x,const auto& y){
            if(x[0]==y[0]) return x[1]>y[1];
            return x[0]<y[0];
        });
        int n = a.size();
        vector<vector<int>> ans;
        for(int i=0;i<n-1;i++){
            int l = max(a[i][0],a[i+1][0]);
            int r = min(a[i][1],a[i+1][1]);
            if(l<=r){
                a[i+1][0] = min(a[i][0],a[i+1][0]);
                a[i+1][1] = max(a[i][1],a[i+1][1]);
            }
            else{
                ans.push_back(a[i]);
            }
        }
        ans.push_back(a[n-1]);
        return ans;
    }
};