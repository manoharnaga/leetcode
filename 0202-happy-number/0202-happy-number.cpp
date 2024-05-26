class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        while(mp.find(n)==mp.end()){
            mp[n] = 1;
            int sum = 0;
            while(n){
                int x = n%10;
                sum += x*x;
                n/=10;
            }
            n = sum;
        }
        return (n==1);
    }
};