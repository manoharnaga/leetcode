class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        
        vector<int> ans;
        vector<set<int>> adj(n);
        
        for(auto it: edges){
            adj[it[0]].insert(it[1]);
            adj[it[1]].insert(it[0]);
        }
        
        vector<int> leaves;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1) leaves.push_back(i);
        }
        
        while(n>2){
            n -= leaves.size();
            vector<int> newLeaves;
            for(int v: leaves){
                int u = *adj[v].begin();
                adj[v].erase(u);
                adj[u].erase(v);
                if(adj[u].size()==1) newLeaves.push_back(u);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};