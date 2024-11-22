class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int val: nums) mp[val]++;
        return (mp.size()<nums.size());
    }
};