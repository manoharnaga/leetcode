class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            dp[i] = n+1;
            for(int j=i+1;j<=(i+nums[i]) && j<n;j++){
                dp[i] = min(dp[i],dp[j]+1);
            }
        }
        // for(int val: dp) cout<<val<<" ";
        // cout<<"\n";
        return dp[0];
    }
};