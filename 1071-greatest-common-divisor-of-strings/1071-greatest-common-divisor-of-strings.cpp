class Solution {
public:
    int check(string t,string s){
        int val = t.size();
        for(int i=0;i<s.size();i+=val){
            if(s.substr(i,val)!=t) return 0;
        }
        return 1;
    }

    string gcdOfStrings(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int x = __gcd(n,m);
        
        for(int i=x;i>=1;i--){
            if(n%i || m%i) continue;
            string s = str1.substr(0,i);
            if(check(s,str1) && check(s,str2)) return s;
        }
        return "";
    }
};