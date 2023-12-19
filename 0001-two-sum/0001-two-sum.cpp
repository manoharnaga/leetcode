class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a;
        a=nums;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ans(2);
        int start=0,end=n-1;
        while(start<=end){
            if((nums[start]+nums[end])==target){
                ans[0]=nums[start];
                ans[1]=nums[end];
                break;
            }
            else if((nums[start]+nums[end])>target){
                end--;
            }
            else{
                start++;
            }
        }
        for(int i=0;i<n;i++){
            if(ans[0]==a[i]){
                ans[0]=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(ans[1]==a[i] && i!=ans[0]){
                ans[1]=i;
                break;
            }
        }
        return ans;
    }
};