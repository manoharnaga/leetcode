class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(),a.end(),[](auto& x,auto& y){
            if(x[0]==y[0]) return x[1]>y[1];
            return x[0]<y[0];
        });
        int cnt = n;
        int ind = 0;
        for(int i=1;i<n;i++){
            if(a[ind][1]>=a[i][1]){
                cnt--;
            }
            else{
                ind = i;
            }
        }
        return cnt;
    }
};