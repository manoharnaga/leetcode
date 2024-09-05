class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right) return left;
        int diff = right-left;
        int ans = 0;
        for(int i=31;i>=0;i--){
            if(((left>>i) & 1)  && ((right>>i) & 1) && diff<=((1<<i)-1)){
                ans += (1<<i);
            }
        }
        return ans;
    }
};