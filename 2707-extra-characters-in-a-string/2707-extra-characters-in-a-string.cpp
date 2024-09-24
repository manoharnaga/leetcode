class Solution {
public:
    map<string,int> mp;
    set<string> d;
    int rec(string s){
        if(s.empty()) return 0;
        if(mp.find(s)!=mp.end()) return mp[s];
        int n = s.size();
        int ans = 1+rec(s.substr(1));
        for(int i=0;i<n;i++){
            string x = s.substr(0,i+1);
            if(d.find(x)!=d.end()){
                int val = rec(s.substr(i+1));
                ans = min(ans,val);
            }
        }
        return mp[s] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        mp.clear();d.clear();
        
        for(string s: dictionary) d.insert(s);
        return rec(s);
    }
};