class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>& a,vector<int>& v,int ind,int x){
        if(x==0){
            ans.push_back(v);
            return;
        }
        if(ind>=a.size()) return;
        if((x-a[ind])<0) return;
        v.push_back(a[ind]);
        rec(a,v,ind,x-a[ind]);
        v.pop_back();
        rec(a,v,ind+1,x);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int x) {
        std::ios::sync_with_stdio(0);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        ans.resize(0);
        sort(a.begin(),a.end());
        vector<int> v;
        rec(a,v,0,x);
        return ans;
    }
};