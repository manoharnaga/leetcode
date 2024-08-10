class Solution {
public:
    void next_permutation(vector<int>& a){
        int n = a.size();
        int ind = -1;
        for(int i=n-1;i>0;i--){
            if(a[i-1]<a[i]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(a.begin(),a.end());
            return;
        }
        reverse(a.begin()+ind,a.end());
        for(int j=ind;j<n;j++){
            if(a[ind-1]<a[j]){
                swap(a[ind-1],a[j]);
                break;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>> ans;
        int n = a.size();
        int sz = 1;
        for(int i=1;i<=n;i++) sz*=i;
        for(int i=0;i<sz;i++){
            ans.push_back(a);
            next_permutation(a);
        }
        return ans;
    }
};