class Solution {
public:
    int trailingZeroes(int mainn) {
        int cnt2 = 0,cnt5 = 0;
        for(int i=1;i<=mainn;i++){
            int n = i;
            while(n>1 && (n%2)==0){
                cnt2++;
                n/=2;
            }
            while(n>1 && (n%5)==0){
                cnt5++;
                n/=5;
            }
        }
        return min(cnt2,cnt5);
    }
};