
class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string x = "";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(!x.empty()){
                    v.push_back(x);
                }
                x = "";
            }
            else{
                x += s[i];
            }
        }
        if(!x.empty())  v.push_back(x);
        reverse(v.begin(),v.end());
        s = "";
        for(string k: v){
            s+=k;
            s+=" ";
        }
        if(!s.empty()) s.pop_back();
        return s;
    }
};