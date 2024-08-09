class Solution {
public:
    vector<vector<int>> ans,dp;
    void rec(vector<int>& a,vector<int>& v,int n,int sum){
        if(sum==0){
            ans.push_back(v);
            return;
        }
        if(sum<0 || n<0) return;
        v.push_back(a[n]);
        rec(a,v,n,sum-a[n]);
        v.pop_back();
        
        rec(a,v,n-1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        int n = a.size();
        dp = vector<vector<int>> (target+1,vector<int>(n,-1));
        ans.clear();
        vector<int> v;
        sort(a.begin(),a.end());
        rec(a,v,n-1,target);
        return ans;
    }
};