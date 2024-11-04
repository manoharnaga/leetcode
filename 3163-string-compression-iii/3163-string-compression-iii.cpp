class Solution {
public:
    string compressedString(string s) {
        string ans;
        int n = s.size(), cnt = 1;
        char ch = s[0];
        for(int i=1;i<n;i++){
            if(ch!=s[i]){
                while((cnt-9)>=0){
                    ans+="9";
                    ans+=ch;
                    cnt -= 9;
                }
                if(cnt>0){
                    ans += to_string(cnt);
                    ans += ch;
                }
                
                cnt = 0;
                ch = s[i];
            }
            cnt++;
        }
        while((cnt-9)>=0){
            ans+="9";
            ans+=ch;
            cnt -= 9;
        }
        if(cnt>0){
            ans += to_string(cnt);
            ans += ch;
        }
        return ans;
    }
};