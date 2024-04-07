class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        int l = 0, r = n - 1;
        while(l<=r){
            ans = max(ans,(r-l)*min(a[l],a[r]));
            if(a[l]<=a[r]) l++;
            else           r--;
        }
        return ans;
    }
};