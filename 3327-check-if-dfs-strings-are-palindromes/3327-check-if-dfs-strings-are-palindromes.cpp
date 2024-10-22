class Solution {
public:
    vector<int> manacher_odd(string s) {
        int n = s.size();
        s = "$" + s + "^";
        vector<int> p(n + 2);
        int l = 1, r = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = max(0, min(r - i, p[l + (r - i)]));
            while(s[i - p[i]] == s[i + p[i]]) {
                p[i]++;
            }
            if(i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
        return vector<int>(begin(p) + 1, end(p) - 1);
    }

    vector<int> manacher(string s) {
        string t;
        for(auto c: s) {
            t += string("#") + c;
        }
        auto res = manacher_odd(t + "#");
        return vector<int>(begin(res) + 1, end(res) - 1);
    }

    vector<int> v,vist,h;
    vector<vector<int>> adj;
    int dfs(int u,string& s,string& x){
        vist[u] = 1;
        h[u] = x.size();
        x+=s[u];
        int cnt = 0;
        for(int v: adj[u]){
            cnt += dfs(v,s,x);
        }
        return v[u] = cnt+1;
    }

    vector<bool> findAnswer(vector<int>& par, string s) {
        int n = s.size();
        adj = vector<vector<int>> (n);
        v = h = vist = vector<int>(n,0);
        for(int i=1;i<n;i++){
            adj[par[i]].push_back(i);
        }
        for(int i=0;i<n;i++){
            sort(adj[i].begin(),adj[i].end(),greater<int>());
        }
        string x = "";
        dfs(0,s,x);
        
        // cout<<x<<"\n";
        
        vector<int> d = manacher(x);
        // cout<<d.size()<<"sz\n";
        vector<bool> ans(n,false);
        
        // for(int i=0;i<d.size();i++) cout<<d[i]<<" ";
        // cout<<"\n";
        
        for(int i=0;i<n;i++){
            int len = v[i];
            int j = h[i]+(len/2);
            int psz = 0;
            if(len%2){
                // odd
                psz = d[2*j]-1;
            }
            else{
                psz = d[2*j-1]-1;
            }
            // cout<<len<<" "<<j<<" "<<psz<<"\n";
            if(psz>=len) ans[i] = true;
        }
        return ans;
    }
};