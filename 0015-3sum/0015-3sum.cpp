class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(i>0 && a[i-1]==a[i]) continue;
            int low = i+1,high = n-1;
            while(low<high){
                int x = a[i]+a[low]+a[high];
                if(x==0){
                    ans.push_back({a[i],a[low],a[high]});
                    int plow = low;
                    int phigh = high;
                    while(low<high && a[plow]==a[low]) low++;
                    while(low<high && a[phigh]==a[high]) high--;
                }
                else if(x<0)    low++;
                else            high--;
            }
        }
        return ans;
    }
};