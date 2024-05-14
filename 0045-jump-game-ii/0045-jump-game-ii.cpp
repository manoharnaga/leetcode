class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = 0,ans = 0,mx = 0;
        while(r<n-1){
            for(int i=l;i<=r;i++) mx = max(mx,i+nums[i]);
            l = r+1;
            r = mx;
            ans++;
        }
        return ans;
    }
};