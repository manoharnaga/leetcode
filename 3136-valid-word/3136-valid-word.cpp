class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        int f1=0,f2=0;
        for(char& ch: word){
            if(ch>='A' && ch<='Z') ch=ch+32;
            if((ch>='a' && ch<='z') || (ch>='A' && ch>='Z') || (ch>='0' && ch<='9')) continue;
            return false;
        }
        for(char ch: word){
            if(ch>='a' && ch<='z'){
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') f1=1;
                else f2 = 1;
            } 
        }
        return f1 && f2;
    }
};