class Solution {
public:
    bool isPalindrome(string s) {
        string x;
        for(char k: s){
            char ch = tolower(k);
            if((ch>='0' && ch<='9') || (ch>='a' && ch<='z')) x+=ch;
        }
        // cout<<x<<"\n";
        int n = x.size();
        for(int i=0;i<(n/2);i++){
            if(x[i]!=x[n-i-1]) return false;
        }
        return true;
    }
};