class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& a, int k) {
        int n = a.size();
        unordered_map<int,int> mp;
        for(int i=0;i<=k && i<n;i++){
            mp[a[i]]++;
            if(mp[a[i]]>1) return true;
        }
        int prev = 0;
        for(int i=k+1;i<n;i++){
            mp[a[prev]]--;
            mp[a[i]]++;
            if(mp[a[i]]>1) return true;
            prev++;
        }
        return false;
    }
};