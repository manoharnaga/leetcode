class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mp;
        int n = grid.size();
        for(auto it: grid){
            mp[it]++;
        }
        int ans = 0;
        for(int j=0;j<n;j++){
            vector<int> x;
            for(int i=0;i<n;i++){
                x.push_back(grid[i][j]);
            }
            if(mp.find(x)!=mp.end()) ans+=mp[x];
        }
        return ans;
    }
};