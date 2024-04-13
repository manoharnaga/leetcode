class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int m = b.size();
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<n && j<m){
            if(a[i][1]<b[j][0]){
                i++;
            }
            else if(b[j][1]<a[i][0]){
                j++;
            }
            else{
                // cout<<i<<j<<"\n";
                if(a[i][0]<b[j][0]){
                    ans.push_back({b[j][0],min(a[i][1],b[j][1])});
                }
                else{
                    ans.push_back({a[i][0],min(b[j][1],a[i][1])});
                }
                if(a[i][1]<b[j][1]){
                    i++;
                }
                else if(a[i][1]==b[j][1]){
                    i++;j++;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};