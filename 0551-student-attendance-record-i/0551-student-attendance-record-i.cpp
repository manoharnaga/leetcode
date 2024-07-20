class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        if(n<=1) return true;
        if(n==2){
            if(s[0]==s[1] && s[0]=='A') return false;
            return true;
        }
        int cnt = 0;
        for(int i=0;i<n-2;i++){
            if(s[i]==s[i+1] && s[i+1]==s[i+2] && s[i]=='L'){
                return false;
            }
            if(s[i]=='A') cnt++;
        }
        if(s[n-2]=='A') cnt++;
        if(s[n-1]=='A') cnt++;
        if(cnt>=2) return false;
        return true;
    }
};