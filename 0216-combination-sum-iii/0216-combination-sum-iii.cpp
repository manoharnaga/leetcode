class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    void rec(vector<int>& x,int ind,int k,int n){
        if(n<0 || k<0) return;
        if(n==0 && k==0){
            ans.push_back(x);
            return;
        }
        if(ind==9) return;
        x.push_back(v[ind]);
        rec(x,ind+1,k-1,n-v[ind]);
        x.pop_back();
        rec(x,ind+1,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.resize(0);
        if((k*(k+1))/2 > n){
            return ans;
        }
        vector<int> x;
        rec(x,0,k,n);
        return ans;
    }
};