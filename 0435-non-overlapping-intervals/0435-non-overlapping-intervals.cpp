class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int n = a.size();
        if(n==1) return 0;
        sort(a.begin(),a.end(),[](const auto& x,const auto& y){
            return x[1]<y[1];
        });
        int ans = 0;
        vector<int> prev = a[0];
        for(vector<int> x: a){
            if(prev[1]>x[0]){
                ans++;
                // cout<<x[0]<<x[1]<<"\n";
            }
            else{
                prev = x;
            }
        }
        return ans-1;
    }
};