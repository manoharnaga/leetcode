class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& x) {
        int n = a.size();
        int ind = n;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(a[i][0]>=x[0]){
                ind = i;
                break;
            }
            ans.push_back(a[i]);
        }
        // cout<<ind<<"\n";
        
        if(ind>0 && a[ind-1][1]>=x[0]){
            ans.back()[1] = max(x[1],a[ind-1][1]);
        }
        else{
            ans.push_back(x);
        }
        
        while(ind<n && ans.back()[1]>=a[ind][0]){
            ans.back()[1] = max(ans.back()[1],a[ind][1]);
            ind++;
        }
        while(ind<n){
            ans.push_back(a[ind]);
            ind++;
        }
        
        return ans;
    }
};