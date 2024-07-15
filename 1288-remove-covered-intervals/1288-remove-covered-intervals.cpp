class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(),a.end(),[](const auto& x,const auto& y){
            if(x[0]==y[0]){
                return x[1]>y[1];
            }
            return x[0]<y[0];
        });
        int end = a[0][1];
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(a[i][1]<=end){
                cnt++;
            }
            else{
                end = a[i][1];
            }
        }
        return (n-cnt);
    }
};