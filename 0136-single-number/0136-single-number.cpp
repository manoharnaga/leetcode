class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int val: nums) x^=val;
        return x;
    }
};