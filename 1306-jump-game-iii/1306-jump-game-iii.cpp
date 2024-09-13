class Solution {
public:
    vector<int> vist;
    void dfs(vector<int>& a,int at,vector<int> adj[]){
        vist[at] = 1;
        for(auto it: adj[at]){
            if(!vist[it]){
                dfs(a,it,adj);
            }
        }
    }
    bool canReach(vector<int>& a, int start) {
        int n = a.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            int v1 = i-a[i];
            int v2 = i+a[i];
            if(v1>=0 && v1<n){
                adj[i].push_back(v1);
                // adj[v1].push_back(i);
            }
            if(v2>=0 && v2<n){
                adj[i].push_back(v2);
                // adj[v2].push_back(i);
            }
        }
        vist = vector<int> (n,0);
        dfs(a,start,adj);
        for(int i=0;i<n;i++){
            if(a[i]==0 && vist[i]) return true;
        }
        return false;
    }
};