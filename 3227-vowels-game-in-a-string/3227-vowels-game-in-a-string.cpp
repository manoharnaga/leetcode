class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for(char ch: s){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                cnt++;
            }
        }
        if(!cnt) return false;
        return true;
    }
};