class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int valley = 0,peak = 0;
        int i=0;
        int ans = 0;
        while(i<n){
            while(i+1<n && prices[i+1]<prices[i]){
                i++;
            }
            valley = i;
            while(i+1<n && prices[i+1]>prices[i]) i++;
            peak = i;
            ans += (prices[peak]-prices[valley]);
            i++;
        }
        return ans;
    }
};