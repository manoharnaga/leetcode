class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> sell(k+1,0),buy(k+1,INT_MIN);
        for(auto p: prices){
            for(int i=1;i<=k;i++){
                buy[i] = max(buy[i],sell[i-1]-p);
                sell[i] = max(sell[i],buy[i]+p);
            }
        }
        return sell[k];
    }
};