class Solution {
public:
    int minChanges(int n, int k) {
        int cnt = 0;
        for(int i=0;i<30;i++){
            int x = (1<<i);
            if((x & n) && !(x & k)){
                cnt++;
                n ^= x;
            }
        }
        if(n==k) return cnt;
        return -1;
    }
};