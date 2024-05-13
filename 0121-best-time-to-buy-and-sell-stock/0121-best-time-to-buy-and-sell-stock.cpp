class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<int> x,y;
        x = a;
        y = a;
        for(int i=1;i<n;i++) x[i]=min(x[i],x[i-1]);
        for(int i=n-2;i>=0;i--) y[i]=max(y[i],y[i+1]);
        int ans = 0;
        for(int i=0;i<n-1;i++){
            ans = max(ans,y[i+1]-x[i]);
        }
        return ans;
    }
};