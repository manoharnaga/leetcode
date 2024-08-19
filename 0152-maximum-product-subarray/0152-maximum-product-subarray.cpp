class Solution {
public:
    typedef double ll;
    int maxProduct(vector<int>& a) {
        int n = a.size();
        ll ans = a[0];
        ll cur = 0;
        for(int i=0;i<n;i++){
            if(cur==0) cur=1;
            cur *= a[i];
            ans = max(ans,cur);
        }
        cur = 0;
        for(int i=n-1;i>=0;i--){
            if(cur==0) cur=1;
            cur *= a[i];
            ans = max(ans,cur);
        }
        return ans;
    }
};