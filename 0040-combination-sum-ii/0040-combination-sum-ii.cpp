class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>& a,vector<int>& v,int ptr,int ind,int x){
        if(x==0){
            ans.push_back(v);
            return;
        }
        if(ind>=a.size()) return;
        if((x-a[ind])<0) return;
        rec(a,v,ptr,ind+1,x);          // no take
        if(ind>0 && a[ind]==a[ind-1] && ptr!=(ind-1)){
            return;
        }
        v.push_back(a[ind]);
        rec(a,v,ind,ind+1,x-a[ind]);   // take
        v.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int x) {
        sort(a.begin(),a.end());
        vector<int> v;
        rec(a,v,-1,0,x);
        return ans;
    }
};