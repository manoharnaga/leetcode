class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        map<char,set<char>> mp;
        
        for(auto it: mappings){
            mp[it[0]].insert(it[1]);
        }
        
        int n = s.size();
        int m = sub.size();
        for(int i=0;i<n;i++){
            int k = i;
            int cnt = 0;
            for(int j=0;j<m && k<n;j++){
                char c = s[k++];
                if(sub[j]==c || mp[sub[j]].find(c)!=mp[sub[j]].end()){
                    cnt++;
                    continue;
                }
                // cout<<k<<" "<<j<<"\n";
                break;
            }
            if(cnt==m){
                return true;
            }
        }
        return false;
    }
};