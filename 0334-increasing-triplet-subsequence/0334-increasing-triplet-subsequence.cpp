class Solution {
public:
    typedef long long ll;
    bool increasingTriplet(vector<int>& nums) {
        ll a,b,c;
        a=b=c=LLONG_MAX;
        for(int i=0;i<nums.size();i++){
            if(a>nums[i]){
                a = nums[i];
            }
            else if(a<nums[i] && b>nums[i]){
                b = nums[i];
            }
            else if(b<nums[i] && c>nums[i]){
                c = nums[i];
            }
            if(a<b && b<c && a!=LLONG_MAX && b!=LLONG_MAX && c!=LLONG_MAX) return true;
        }
        return false;
    }
};