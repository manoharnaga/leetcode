class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = a.size();
        auto cmp = [&](auto x,auto y){
            if(x[1]==y[1]) return x[0]<y[0];
            return x[1]<y[1];
        };
        sort(a.begin(),a.end(),cmp);
        int end = a[0][1];
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(a[i][0]<end){
                cnt++;
            }
            else{
                end = a[i][1];
            }
        }
        return cnt;
    }
};