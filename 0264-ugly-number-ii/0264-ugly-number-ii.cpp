class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(1,1);
        int i=0,j=0,k=0;
        while(dp.size()<n){
            dp.push_back(min({dp[i]*2,dp[j]*3,dp[k]*5}));
            if(dp[i]*2 == dp.back()) i++;
            if(dp[j]*3 == dp.back()) j++;
            if(dp[k]*5 == dp.back()) k++;
        }
        return dp.back();   
    }
};