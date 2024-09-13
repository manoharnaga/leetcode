class Solution {
public:
    #define all(a) a.begin(), a.end()
    vector<int> fallingSquares(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = v[i][1];
            int l,r;
            l = v[i][0],r = l+v[i][1];
            for(int j=0;j<i;j++){
                int x = max(v[j][0],l);
                int y = min(v[j][0]+v[j][1],r);
                if(x<y){
                    ans[i] = max(ans[i],ans[j]+v[i][1]);
                }
            }
        }
        for(int i=1;i<n;i++) ans[i] = max(ans[i],ans[i-1]);
        return ans;
    }
};