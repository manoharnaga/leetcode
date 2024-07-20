class Solution {
private:
    vector<vector<int>> ans;
    
public:
    void rec(vector<int>& a,int n,vector<int>& v,int sum){
        if(n<0 || sum<0) return;
        if(sum==0){
            ans.push_back(v);
            return;
        }
        
        v.push_back(a[n]); // take
        rec(a,n,v,sum-a[n]);
        v.pop_back();
        rec(a,n-1,v,sum); // no take
    }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        ans.clear();
        int n = a.size();
        sort(a.begin(),a.end());
        vector<int> v;
        rec(a,n-1,v,target);
        return ans;
    }
};