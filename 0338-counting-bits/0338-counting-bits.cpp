class Solution {
public:
    vector<int> countBits(int n) {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);
        vector<int> ans(n+1,0);
        ans[0] = 0;
        for(int i=0;i<=n;i++){
            ans[i] = ans[i/2]+(i%2);
        }
        return ans;
    }
};