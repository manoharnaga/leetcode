class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        map<int,int> mp;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(mp[(target-a[i])]){
                return {mp[target-a[i]]-1,i};
            }
            mp[a[i]] = i+1;
        }
        return {-1,-1};
    }
};