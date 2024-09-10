class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell1,sell2,buy1,buy2;
        buy1 = buy2 = INT_MIN;
        sell1 = sell2 = 0;
        int n = prices.size();
        for(int p: prices){
            buy1 = max(buy1,-p);
            sell1 = max(sell1,buy1+p);
            buy2 = max(buy2,sell1-p);
            sell2 = max(sell2,buy2+p);
        }
        return sell2;
    }
};