class Solution {
public:
    int ans = 0;
    void dfs(int node,int par,vector<vector<pair<int,int>>>& adj){
        for(auto it: adj[node]){
            int child = it.first,sign = it.second;
            if(child != par){
                ans += sign;
                dfs(child,node,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        ans = 0;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: connections){
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }
        dfs(0,-1,adj);
        return ans;
    }
};