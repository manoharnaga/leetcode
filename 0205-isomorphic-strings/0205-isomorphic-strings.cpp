class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        set<char> st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end() || st.find(t[i])!=st.end()){
                if(mp[s[i]]!=t[i]) return false;
                // continue;
            }
            
            if(s[i]!=t[i]){
                if(mp.find(s[i])!=mp.end()){
                    if(mp[s[i]]!=t[i]){
                        return false;
                    }
                }
            }
            mp[s[i]] = t[i];
            st.insert(t[i]);
        }
        return true;
    }
};