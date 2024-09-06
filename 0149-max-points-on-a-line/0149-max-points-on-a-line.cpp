class Solution {
public:
    int maxPoints(vector<vector<int>>& a) {
        int n = a.size();
        if(n<=2) return n;
        int ans = 0;
        for(int i=0;i<n;i++){
            map<double,int> mp;
            for(int j=i+1;j<n;j++){
                if((a[j][0]-a[i][0])==0){
                    mp[INT_MAX]++;
                }
                else{
                    double slope = ((double)(a[j][1]-a[i][1]))/(a[j][0]-a[i][0]);
                    mp[slope]++;
                }
            }
            int h = 0;
            for(auto it: mp){
                h = max(h,it.second+1);
            }
            ans = max(ans,h);
        }
        return ans;
    }
};