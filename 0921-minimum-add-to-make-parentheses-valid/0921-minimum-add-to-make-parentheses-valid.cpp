class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int moves = 0;
        for(char ch: s){
            if(ch=='('){
                cnt++;
            }
            else{
                if(cnt>0) cnt--;
                else      moves++;
            }
        }
        moves += cnt;
        return moves;
    }
};