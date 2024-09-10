class Solution {
public:
    int maxPoints(vector<vector<int>>& v) {
        int n = v.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            map<double,int> mp;
            for(int j=i+1;j<n;j++){
                if(v[j][0]==v[i][0]){
                    mp[INT_MAX]++;
                }
                else{
                    double slope = (((double)v[j][1]-v[i][1]))/(v[j][0]-v[i][0]);
                    mp[slope]++;
                }
            }
            for(auto it: mp){
                ans = max(ans,it.second+1);
            }
        }
        return ans;
    }
};