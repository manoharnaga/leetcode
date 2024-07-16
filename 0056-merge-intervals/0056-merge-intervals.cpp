class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](const auto& x,const auto& y){
            if(x[0]==y[0]) return x[1]>y[1];
            return x[0]<y[0];
        });
        int ind = 0;
        int n = a.size();
        
        for(int i=1;i<n;i++){
            if(a[i][0]<=a[ind][1]){
                a[ind][1] = max(a[ind][1],a[i][1]);
                if(a[i][1]>a[ind][1]){
                    ind = i;
                }
                a[i][0] = a[i][1] = -1;
            }
            else{
                ind = i;
            }
        }
        vector<vector<int>> ans;
        for(auto it: a){
            if(it[0]==-1 && it[1]==-1) continue;
            ans.push_back(it);
        }
        return ans;
    }
};