class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end(),[](const auto& x,const auto& y){
            if(x[1]==y[1]) return x[0]<y[0];
            return x[1]<y[1];
        });
        vector<int> x = a[0];
        if(n==1) return 1;
        int ans = 0;
        for(int i=1;i<n;i++){
            if(x[1]>=a[i][0]){
                ans++;
            }
            else{
                x = a[i];
            }
        }
        // ans--; // don't consider first 
        return (n-ans);// just return the number of actual non-overlapping intervals
        // the other removed intervals will overlap with one of the non-overlapping intervals
    }
};