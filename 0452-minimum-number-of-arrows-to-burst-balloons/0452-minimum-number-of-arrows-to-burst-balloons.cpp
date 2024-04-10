class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        int minval = a[0][1];
        int cnt = 1;
        int f = 0;
        for(int i=1;i<n;i++){
            if(minval<a[i][0]){
                cnt++;
                minval = a[i][1];
            }
            else{
                minval = min(a[i][1],minval);
            }
        }
        return cnt;
    }
};