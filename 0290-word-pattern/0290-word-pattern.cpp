class Solution {
public:
    bool wordPattern(string pattern, string s) {
        set<pair<string,string>> st;
        set<string> s2;
        stringstream x(s);
        string word;
        int i=0;
        while(x >> word){
            if(i==pattern.size()) return false;
            string x = "";
            x+="-";
            x+=pattern[i++];
            if(st.find({word,x})==st.end()){
                if(s2.find(x)!=s2.end() || s2.find(word)!=s2.end()){
                    // cout<<word<<x<<"\n";
                    // cout<<"helo\n";
                    return false;
                }
            }
            // else continue;
            st.insert({word,x});
            s2.insert(word);
            s2.insert(x);
        }
        if(i<pattern.size()) return false;
        return true;
    }
};