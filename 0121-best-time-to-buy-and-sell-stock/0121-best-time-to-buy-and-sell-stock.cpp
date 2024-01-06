class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int maxsofar = a[n-1];
        for(int i=n-1;i>=0;i--){
            ans = max(ans,maxsofar-a[i]);
            maxsofar = max(maxsofar,a[i]);
        }
        return ans;
    }
};