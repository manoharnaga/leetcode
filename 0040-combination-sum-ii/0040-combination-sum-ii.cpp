class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>& a,vector<int>& v,int n,int f,int sum){
        if(sum==0){
            ans.push_back(v);
            return;
        }
        if(sum<0 || n<0) return;
        rec(a,v,n-1,0,sum);      // no take
        
        if((n+1)<a.size() && a[n+1]==a[n] && !f) return;
        v.push_back(a[n]);
        rec(a,v,n-1,1,sum-a[n]); // take
        v.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        int n = a.size();
        // dp = vector<vector<int>> (target+1,vector<int>(n,-1));
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        vector<int> v;
        int f = 0;
        rec(a,v,n-1,f,target);
        return ans;
    }
};