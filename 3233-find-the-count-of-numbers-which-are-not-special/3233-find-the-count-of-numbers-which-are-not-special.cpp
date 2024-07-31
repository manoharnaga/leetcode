class Solution {
public:
    bool isPrime(int x) {
        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0)
                return false;
        }
        return x >= 2;
    }

    int nonSpecialCount(int l, int r) {
        int x = ceil(sqrt(l));
        int y = sqrt(r);
        int primes = 0;
        for(int i=x;i<=y;i++){
            if(isPrime(i)) primes++;
        }
        return (r-l+1-primes);
    }
};