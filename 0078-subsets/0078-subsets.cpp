class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>& x,vector<int>& a,int ind){
        if(ind==a.size()){
            ans.push_back(x);
            return;
        }
        rec(x,a,ind+1);
        x.push_back(a[ind]);
        rec(x,a,ind+1);
        x.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> x;
        rec(x,nums,0);
        return ans;
    }
};