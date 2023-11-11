class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& a) {
        unordered_map<int,vector<int>> v;
        
        for(auto it: a){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        for(auto it: v){
            if(it.second.size() == 1){
                ans.push_back(it.first);
                ans.push_back(it.second[0]);
                break;
            }
        }
        while(ans.size()<a.size()+1){
            int tail = ans.back();
            int prev = ans[ans.size()-2];
            if(v[tail][0]!=prev){
                ans.push_back(v[tail][0]);
            }
            else{
                ans.push_back(v[tail][1]);
            }
        }
        return ans;
    }
};