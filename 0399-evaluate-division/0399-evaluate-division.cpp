class Solution {
public:
    double ans;
    void dfs(vector<pair<int,double>> adj[],vector<int>& vist,int at,int dest,double div){
        if(at==dest){
            ans = div;
            return;
        }
        if(ans!=-1.0) return;
        vist[at] = 1;
        for(auto it: adj[at]){
            if(ans!=-1.0) return;
            if(!vist[it.first]){
                dfs(adj,vist,it.first,dest,div*it.second);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        map<string,int> mp;
        int cnt = 1;
        for(auto it: eq){
            string num = it[0];
            string den = it[1];
            if(!mp[num]){
                mp[num] = cnt;
                cnt++;
            }
            if(!mp[den]){
                mp[den] = cnt;
                cnt++;
            }
        }
        int n = mp.size();
        vector<pair<int,double>> adj[n+5];
        for(int i=0;i<values.size();i++){
            double val = values[i];
            int u,v;
            u = mp[eq[i][0]];
            v = mp[eq[i][1]];
            // cout<<val<<" "<<(1.0/val)<<"\n";
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }
        vector<double> temp;
        for(auto it: queries){
            if(!mp[it[0]] || !mp[it[1]]){
                temp.push_back(-1.0);
                continue;
            }
            int u,v;
            u = mp[it[0]];
            v = mp[it[1]];
            ans = -1.0;
            // DFS/BFS
            vector<int> vist(n+1,0);
            dfs(adj,vist,u,v,1.0);
            temp.push_back(ans);
        }
        return temp;
    }
};