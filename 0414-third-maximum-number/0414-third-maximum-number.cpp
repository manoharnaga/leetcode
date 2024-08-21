class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long a,b,c;
        a = b = c = numeric_limits<long long>::min();
        for(int i=0;i<nums.size();i++){
            // cout<<a<<" "<<b<<" "<<c<<"\n";
            if(c<nums[i]){
                a = b;
                b = c;
                c = nums[i];
            }
            else if(b<nums[i] && nums[i]!=c){
                a = b;
                b = nums[i];
            }
            else if(a<nums[i] && nums[i]!=b && nums[i]!=c){
                a = nums[i];
            }
        }
        if(a==numeric_limits<long long>::min()) return c;
        return a;
    }
};