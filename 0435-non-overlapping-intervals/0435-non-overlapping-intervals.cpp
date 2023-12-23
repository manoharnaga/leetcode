class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(),a.end(),[](const auto& x,const auto& y){
            if(x[1]==y[1]){
                return x[0]<y[0];
            }
            return x[1]<y[1];
        });
        int cnt = 0;
        int prev = a[0][1];
        // cout<<prev<<"x\n";
        for(int i=1;i<n;i++){
            // cout<<a[i][0]<<"yz\n";
            if(prev > a[i][0]){
                cnt++;
            }
            else{
                prev = a[i][1];
            }
        }
        return cnt;
    }
};