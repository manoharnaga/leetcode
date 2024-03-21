class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> pref,suff,ans;
        pref = suff = a;
        for(int i=1;i<n;i++) pref[i]=pref[i-1]*a[i];
        for(int i=n-2;i>=0;i--) suff[i]=suff[i+1]*a[i];
        for(int i=0;i<n;i++){
            int val = 1;
            if(i>0) val*=pref[i-1];
            if(i+1<n) val*=suff[i+1];
            ans.push_back(val);
        }
        return ans;
    }
};