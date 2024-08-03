class Solution {
public:
    typedef long long ll;
    ll rec(vector<int>& a,ll l,ll r){
        // cout<<l<<" "<<r<<"x\n";
        if(l>r) return 0ll;
        for(int i=l;i<=r;i++) a[i]=abs(a[i]);
        if(l==r) return a[l];
        ll minval = a[l];
        for(int i=l;i<=r;i++){
            minval = min(minval,(ll)a[i]);
        }
        ll sum = minval;
        ll prevind = l;
        for(int i=l;i<=r;i++){
            a[i] -= minval;
            if(a[i]==0){
                sum += rec(a,prevind,i-1);
                prevind = i+1;
            }
        }
        sum += rec(a,prevind,r);
        // cout<<sum<<"\n";
        return sum;
    }
    long long minimumOperations(vector<int>& a, vector<int>& b) {
        int n = a.size();
        for(int i=0;i<n;i++){
            a[i] = b[i]-a[i];
        }
        // 0 -> -1
        // 1 -> 1
        int i = 0;
        while(i<n && a[i]==0) i++;
        if(i==n) return 0ll;
        ll prevind = 0;
        ll ans = 0,sum=0,prev=0;
        int par = (a[i]>0); 
        for(i;i<n;i++){
            if(par!=(a[i]>0) || a[i]==0){
                ans += rec(a,prevind,i-1);
                while(i<n && a[i]==0) i++;
                prevind = i;
                if(i<n) par = (a[i]>0);
            }
        }
        ans += rec(a,prevind,n-1);
        return ans;
    }
};