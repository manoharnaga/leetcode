class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ind = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(!cnt){
                ind = i;
                cnt = 1;
                continue;
            }
            if(nums[ind]==nums[i]){
                cnt++;
                
            }
            else{
                cnt--;
            }
        }
        return nums[ind];
    }
};