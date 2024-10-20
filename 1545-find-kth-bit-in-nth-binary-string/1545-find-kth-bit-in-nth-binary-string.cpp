class Solution {
public:
    void invert(string& s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') s[i]='1';
            else          s[i]='0';
        }
    }
    char findKthBit(int n, int k) {
        string x = "0";
        for(int i=1;i<n;i++){
            string y = x;
            invert(y);
            reverse(y.begin(),y.end());
            x += "1";
            x += y;
        }
        return x[k-1];
    }
};