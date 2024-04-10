class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int cnt = 0;
            for(int j=0;j<31;j++){
                if(i & (1<<j)){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};