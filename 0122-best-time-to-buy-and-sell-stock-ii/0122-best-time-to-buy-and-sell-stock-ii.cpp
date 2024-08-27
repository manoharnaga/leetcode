class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int valley = 0,peak = 0;
        int n = prices.size();
        int ans = 0,i = 0;
        while(i<n){
            while((i+1)<n && prices[i+1]<prices[i]) i++;
            valley = i;
            while((i+1)<n && prices[i+1]>prices[i]) i++;
            peak = i;
            ans += (prices[peak]-prices[valley]);
            i++;
        }
        return ans;
    }
};