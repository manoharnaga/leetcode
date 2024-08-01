class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if(n==1) return 0;
        vector<int> pref(n),suff(n);
        int ans = 0;
        pref = suff = a;
        for(int i=1;i<n;i++){
            pref[i] = min(pref[i-1],a[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i] = max(suff[i+1],a[i]);
        }
        for(int i=0;i<n-1;i++){
            ans = max(ans,(suff[i+1]-pref[i]));
        }
        return ans;
    }
};