class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n = a.size();
        if(n==1) return 0;
        
        vector<int> l,r;
        int i,j;
        l.push_back(a[0]);
        for(i=1;i<n;i++){
            if(a[i-1]<=a[i]){
                l.push_back(a[i]);
            }
            else break;
        }
        if(i==n) return 0;
        
        r.push_back(a[n-1]);
        for(j=n-2;j>=i;j--){
            if(a[j]<=a[j+1]){
                r.push_back(a[j]);
            }
            else break;
        }
        reverse(r.begin(),r.end());
        int lsz=l.size(),rsz=r.size();
        int cnt = max(lsz,rsz);
        
        for(i=0;i<lsz;i++){
            int x = l[i];
            int idx = lower_bound(r.begin(),r.end(),x)-r.begin();
            // cout<<idx<<"kk\n";
            if(idx==rsz) continue;
            cnt = max(cnt,i+1+(rsz-idx));
        }
        
        // for(int val: l) cout<<val<<" ";
        // cout<<"\n";
        // for(int val: r) cout<<val<<" ";
        // cout<<"\n";
        return max((n-cnt),0);
    }
};