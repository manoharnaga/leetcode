class Solution {
public:
    string removeStars(string s) {
        int end = 0;
        for(char ch: s){
            if(ch=='*') end--;
            else        s[end++]=ch;
        }
        return s.substr(0,end);
    }
};