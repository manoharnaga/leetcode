class Solution {
public:
    set<vector<int>> st;
    void rec(vector<int>& a,vector<int> v,int n){
        if(n<0){
            sort(v.begin(),v.end());
            st.insert(v);
            return;
        }
        rec(a,v,n-1);
        
        v.push_back(a[n]);
        rec(a,v,n-1);
        v.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        int n = a.size();
        vector<int> v;
        rec(a,v,n-1);
        vector<vector<int>> ans;
        for(auto it: st) ans.push_back(it);
        return ans;
    }
};