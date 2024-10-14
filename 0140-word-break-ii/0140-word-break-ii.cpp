class Solution {
public:
    vector<string> v;
    set<string> st;
    string x;
    void rec(int i,string cur,string& s){
        if(i==s.size()){
            if(cur.empty()) v.push_back(x);
            return;
        }
        cur += s[i];
        string temp = x;
        rec(i+1,cur,s);
        
        if(st.find(cur)!=st.end()){
            if(!x.empty()) x+=" ";
            x += cur;
            rec(i+1,"",s);
        }
        x = temp;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st.clear();
        for(string i: wordDict) st.insert(i);
        x = "";
        string cur;
        rec(0,cur,s);
        return v;
    }
};