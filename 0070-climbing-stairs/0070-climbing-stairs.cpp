class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int f1=1,f2=2,ans=2;
        for(int i=3;i<=n;i++){
            ans = f1+f2;
            f1 = f2;
            f2  = ans;
        }
        return ans;
    }
};