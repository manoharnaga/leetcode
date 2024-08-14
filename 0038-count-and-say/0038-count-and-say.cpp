class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        char ch;
        for(int j=1;j<n;j++){
            int cnt=1;
            string t = "";
            for(int i=1;i<s.size();i++){
                if(s[i]!=s[i-1]){
                    t += to_string(cnt);
                    t += s[i-1];
                    cnt = 1;
                }
                else{
                    cnt++;
                }
            }
            if(j==1) t="11";
            else{
                t += to_string(cnt);
                t += s[s.size()-1];
            }
            s = t;
        }
        return s;
    }
};