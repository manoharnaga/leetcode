class Solution {
public:
    void dfs(int at,vector<int> adj[],vector<int>& vist1){
        vist1[at] = 2;
        for(int it: adj[at]){
            if(!vist1[it]){
                dfs(it,adj,vist1);
            }
        }
    }
    int flag;
    void dfs2(int at,vector<int> adj[],vector<int>& vist1,vector<int>& vist2){
        // cout<<at<<"k\n";
        if(vist1[at]==2){
            flag = 1;
        }
        vist2[at] = 1;
        for(int it: adj[at]){
            if(!vist2[it]){
                dfs2(it,adj,vist1,vist2);
            }
        }
    }
    
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& v) {
        vector<int> adj[n];
        for(auto it: v){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        vector<int> vist1(n),vist2(n);
        dfs(k,adj,vist1);
        
        flag = 0;
        for(int i=0;i<n;i++){
            if(flag) break;
            if(!vist1[i]){
                // cout<<i<<"\n";
                dfs2(i,adj,vist1,vist2);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vist1[i] || flag) ans.push_back(i);
        }
        return ans;
    }
};