class Solution {
public:
    set<vector<int>> st;
    void rec(vector<int>& a, int n, vector<int>& v, int sum){
        if(sum==0){
            st.insert(v);
            return;
        }
        if(n<0 || sum<0) return;
        v.push_back(a[n]);
        rec(a,n-1,v,sum-a[n]);
        v.pop_back();
        while((n-1)>=0 && a[n-1]==a[n]) n--;
        rec(a,n-1,v,sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        st.clear();
        sort(a.begin(),a.end());
        // reverse(a.begin(),a.end());
        int n = a.size();
        vector<int> v;
        rec(a,n-1,v,target);
        vector<vector<int>> ans;
        for(auto it: st) ans.push_back(it);
        return ans;
    }
};