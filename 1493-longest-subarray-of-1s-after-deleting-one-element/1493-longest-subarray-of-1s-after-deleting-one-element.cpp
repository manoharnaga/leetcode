class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size();
        if(n==1) return 0;
        vector<int> pref(n,0),suff(n,0),v(n,0);
        pref[0]=a[0];
        v[0] = pref[0];
        suff[n-1]=a[n-1];
        v[1] = suff[n-1];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+a[i];
            if(!a[i]){
                v[i] = pref[i-1];
                pref[i]=0;
            }
        }
        int ans = 0;
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+a[i];
            if(!a[i]){
                v[i] += suff[i+1];
                suff[i] = 0;
            }
            ans = max(ans,v[i]);
        }
        int x = count(a.begin(),a.end(),1);
        if(x==n) ans = n-1;
        return ans;
    }
};