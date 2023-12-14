class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int cnt = 0;
        int end = a[0][1];
        for(int i=1;i<n;i++){
            if(end>=a[i][0]){
                end = min(end,a[i][1]);
            }
            else{
                cnt++;
                end = a[i][1];
            }
        }
        return (cnt+1);
    }
};