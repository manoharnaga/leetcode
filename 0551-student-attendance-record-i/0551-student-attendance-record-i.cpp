class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for(char ch: s){
            if(ch=='A') a++;
            (ch=='L') ? l++: l=0;
            if(a>1 || l>=3) return false;
        }
        return true;
    }
};