class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i=0;i<31;i++){
            int x = (1<<i);
            if(c & x){
                if(!(a & x) && !(b & x)) cnt++;
            }
            else{
                if(a & x) cnt++;
                if(b & x) cnt++;
            }
        }
        return cnt;
    }
};