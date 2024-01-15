class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(int val: arr) mp[val]++;
        vector<int> v(1010,0);
        for(auto it:mp){
            v[it.second]++;
        }
        for(int i=0;i<=1000;i++){
            if(v[i]>1) return false;
        }
        return true;
    }
};