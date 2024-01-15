class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        set<int> s1,s2;
        for(int val: nums1) s1.insert(val);
        for(int val: nums2) s2.insert(val);
        for(int val: s1){
            if(s2.find(val)==s2.end()){
                ans[0].push_back(val);
            }
        }
        for(int val: s2){
            if(s1.find(val)==s1.end()){
                ans[1].push_back(val);
            }
        }
        return ans;
    }
};