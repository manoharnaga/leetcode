class Solution {
public:
    void dfs(vector<vector<int>>& adj,int at,vector<int>& vist){
        vist[at] = 1;
        for(int i:adj[at]){
            if(!vist[i]){
                dfs(adj,i,vist);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vist(n),v(n,1);
        dfs(adj,0,vist);
        return (vist==v);
    }
};