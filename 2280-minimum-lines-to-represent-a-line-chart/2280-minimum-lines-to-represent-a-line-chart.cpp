class Solution {
public:
    int minimumLines(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        int dx,dy;
        dx = dy = INT_MIN;
        int n = a.size();
        int cnt = 0;
        for(int i=1;i<n;i++){
            int dx1 = a[i][0]-a[i-1][0];
            int dy1 = a[i][1]-a[i-1][1];
            int d = __gcd(dx1,dy1);
            cnt += (dx!=(dx1/d)) || (dy!=(dy1/d));
            dx = dx1/d;
            dy = dy1/d;
        }
        return cnt;
    }
};