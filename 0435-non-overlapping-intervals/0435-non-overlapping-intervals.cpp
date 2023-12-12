class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = a.size();
        if(n==1) return 0;
        sort(a.begin(),a.end());
        int l=0,r=1;
        int ans = 0;
        while(r<n){
            if(a[r][0]<a[l][1]){
                if(a[r][1]<a[l][1]){
                    l = r;
                }
                ans++;
            }
            else{
                l = r;
            }
            r++;
        }
        return ans;
    }
};