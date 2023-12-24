class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(),a.end(),[](const auto& x,const auto& y){
            if(x[1]==y[1]) return x[0]<y[0];
            return x[1]<y[1];
        });
        int cnt = 0;
        int prev = a[0][1];
        for(int i=0;i<n;i++){
            if(prev >= a[i][0]){
                cnt++;
            }
            else{
                prev = a[i][1];
            }
        }
        // cout<<cnt<<"\n";
        return (n-cnt+1);
    }
};