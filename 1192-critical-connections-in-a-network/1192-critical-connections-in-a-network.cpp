class Solution {
public:
    vector<vector<int>> res;
    vector<int> disc,low;
    int timer;
    void dfs(int u,int par,vector<vector<int>>& adj){
        disc[u] = low[u] = timer++;
        for(int v: adj[u]){
            if(v==par) continue;
            if(disc[v]==-1){
                dfs(v,u,adj);
                low[u] = min(low[u],low[v]);
                if(low[v]>disc[u]){
                    res.push_back({u,v});
                }
            }
            else{
                low[u] = min(low[u],disc[v]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        timer = 0;
        disc = low = vector<int>(n,-1);
        vector<vector<int>> adj(n);
        
        for(auto& it: conn){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfs(0,-1,adj);
        return res;
    }
};