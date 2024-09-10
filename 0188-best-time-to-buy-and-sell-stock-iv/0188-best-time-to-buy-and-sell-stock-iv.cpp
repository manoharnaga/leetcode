class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        vector<int> buy(K+1,INT_MIN),sell(K+1,0);
        for(auto p: prices){
            for(int k=1;k<=K;k++){
                buy[k] = max(buy[k],sell[k-1]-p);
                sell[k] = max(sell[k],buy[k]+p);
            }
        }
        return sell[K];
    }
};