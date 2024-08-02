class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int ans = INT_MIN;
        int maxsofar = 0;
        for(int i=0;i<a.size();i++){
            maxsofar += a[i];
            ans = max(maxsofar,ans);
            maxsofar = max(maxsofar,0);
        }
        return ans;
    }
};