class Solution {
public:
    int a[26],b[26],c[26],d[26];
    
    int check(){
        for(int i=0;i<26;i++){
            if(a[i]>b[i]) return 0;
        }
        for(int i=0;i<26;i++){
            if(c[i]>d[i]) return 0;
        }
        return 1;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0,e = 0;
        for(int i=0;i<26;i++){
            a[i] = b[i] = c[i] = d[i] = 0;
        }
        for(char ch: t){
            if(ch>='a' && ch<='z') a[ch-'a']++;
            else                   c[ch-'A']++;
        }
        int pL = 0,pR = n;
        while(e<n){
            char ch = s[e];
            if(ch>='a' && ch<='z') b[ch-'a']++;
            else                   d[ch-'A']++;
            while(l<=e && check()){
                if((e-l+1)<(pR-pL+1)){
                    pL = l;
                    pR = e;
                }
                ch = s[l];
                if(ch>='a' && ch<='z') b[ch-'a']--;
                else                   d[ch-'A']--;
                l++;
            }
            e++;
        }
        if(pR==n) return "";
        string ans = s.substr(pL,pR-pL+1);
        return ans;
    }
};