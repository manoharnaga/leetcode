class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int start = a[0][0],end = a[0][1];
        for(int i=1;i<a.size();i++){
            if(end>=a[i][0]){
                end = max(a[i][1],end);
            }
            else{
                ans.push_back({start,end});
                start = a[i][0];
                end = a[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};