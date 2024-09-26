class Solution {
public:
    int dfs(vector<vector<int>>& adj,int at,vector<int>& col,int colval){
        col[at] = colval;
        for(int it: adj[at]){
            if(col[it]==colval) return true;
            if(!col[it]){
                if(dfs(adj,it,col,(colval==2 ? 1: 2))) return true;
            }
        }
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        int N = adj.size();
        vector<int> col(N,0);
        
        for(int i=0;i<N;i++){
            if(!col[i]){
                if(dfs(adj,i,col,1)) return false;
            }
        }
        // for(int i=0;i<5;i++) cout<<col[i]<<" ";
        // cout<<"\n";
        
        return true;
    }
};