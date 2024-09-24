class Solution {
public:
    void dfs(vector<int> adj[],vector<int>& h,int at){
        vector<int> col_vis(4,0);
        for(int it: adj[at]){
            if(h[it]!=-1) col_vis[h[it]-1]++;
        }
        
        int col = 1;
        for(;col<=4;col++){
            if(!col_vis[col-1]){
                break;
            }
        }
        h[at] = col;
        for(int it: adj[at]){
            if(h[it]==-1)
                dfs(adj,h,it);
        }
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n];
        vector<int> h(n,-1);
        for(auto it: paths){
            int u = it[0]-1;
            int v = it[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(h[i]==-1){
                dfs(adj,h,i);
            }
        }
        return h;
    }
};