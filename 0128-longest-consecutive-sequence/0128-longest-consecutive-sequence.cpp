class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i: nums){
            if(!mp[i]){
                mp[i] = 1+mp[i-1]+mp[i+1];
                mp[i-mp[i-1]] = mp[i];
                mp[i+mp[i+1]]=mp[i];
            }
            ans = max(ans,mp[i]);
        }
        return ans;
    }
};