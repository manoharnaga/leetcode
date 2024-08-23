class Solution {
public:
    int dfs(vector<int> adj[],int at,vector<int>& vist,string& s,int& ans){
        vist[at] = 1;
        int cnt = 1;
        vector<int> child;
        for(auto it: adj[at]){
            if(!vist[it]){
                int val = dfs(adj,it,vist,s,ans);
                if(s[at]!=s[it]){
                    child.push_back(val);
                    cnt = max(cnt,1+val);
                }
            }
        }
        sort(child.begin(),child.end());
        if(child.size()>1){
            ans = max(ans,child[child.size()-1]+1+child[child.size()-2]);
        }
        ans = max(ans,cnt);
        return cnt;
    }

    int longestPath(vector<int>& par, string s) {
        int n = s.size();
        if(n==1) return 1;
        
        vector<int> adj[n];
        map<int,int> mp;
        for(int i=1;i<n;i++){
            mp[par[i]]++;
            adj[i].push_back(par[i]);
            adj[par[i]].push_back(i);
        }
        int node=1;
        while(node<n){
            if(!mp[node]){
                break;
            }
            node++;
        }
        // cout<<node<<"\n";
        vector<int> vist(n);
        int ans = 0;
        dfs(adj,node,vist,s,ans);
        return ans;
    }
};