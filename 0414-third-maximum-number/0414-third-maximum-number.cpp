class Solution {
public:
    typedef long long ll;
    int thirdMax(vector<int>& nums) {
        ll m1,m2,m3;
        m1 = m2 = m3 = LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            if(m3<nums[i]){
                m1 = m2;
                m2 = m3;
                m3 = nums[i];
            }
            else if(m2<nums[i] && m3!=nums[i]){
                m1 = m2;
                m2 = nums[i];
            }
            else if(m1<nums[i] && m2!=nums[i] && m3!=nums[i]){
                m1 = nums[i];
            }
        }
        // cout<<m1<<" "<<m2<<" "<<m3<<"\n";
        if(m1==LLONG_MIN) return m3;
        return m1;
    }
};