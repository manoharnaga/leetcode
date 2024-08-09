class Solution {
public:
    set<vector<int>> st;
    void rec(vector<int>& a,vector<int>& v,int n){
        if(n<0){
            vector<int> v2 = v;
            sort(v2.begin(),v2.end());
            st.insert(v2);
            return;
        }
        v.push_back(a[n]);
        rec(a,v,n-1); // take
        v.pop_back();
        
        rec(a,v,n-1); // no take
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