class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long k = n;
        int f=0;
        if(k<0){
            k = -k;
            f = 1;
        }
        while(k){
            if(k & 1){
                res *= x;
            }
            x *= x;
            k>>=1;
        }
        if(f) return 1.0/res;
        return res;
    }
};