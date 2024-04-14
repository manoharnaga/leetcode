class StockSpanner {
public:
    stack<pair<int,int>> st;
    int n;
    StockSpanner() {
        n = 0;
        st = stack<pair<int,int>>();
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans;
        if(!st.empty()){
            ans = n-st.top().second;
        }
        else{
            ans = n+1;
        }
        n++;
        st.push({price,n-1});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */