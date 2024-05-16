class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        map<int,int> mp;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(mp.find(a[i])!=mp.end()){
                return {mp[a[i]]+1,i+1};
            }
            mp[(x-a[i])] = i;
        }
        return {-1,-1};
    }
};