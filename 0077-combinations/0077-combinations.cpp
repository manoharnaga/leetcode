class Solution {
public:
    vector<vector<int>> ans;
    void rec(int n,int i,int k,vector<int>& v){
        if(k==0){
            ans.push_back(v);
            return;
        }
        if(i>n) return;
        v.push_back(i);
        rec(n,i+1,k-1,v);
        v.pop_back();
        rec(n,i+1,k,v);
    }

    vector<vector<int>> combine(int n, int k) {
        ans.resize(0);
        vector<int> v;
        rec(n,1,k,v);
        return ans;
    }
};