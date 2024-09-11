class Solution {
public:
    typedef long long ll;
    vector<vector<long long>> splitPainting(vector<vector<int>>& a) {
        map<int,ll> mp;
        for(auto it: a){
            mp[it[0]]+=it[2];
            mp[it[1]]-=it[2];
        }
        ll cumulativeShift = 0;
        for(auto& it: mp){
            it.second += cumulativeShift;
            cumulativeShift = it.second;
        }
        vector<vector<ll>> v;
        int prev = -1;
        ll prevval = -1;
        for(auto it: mp){
            
            if(prev!=-1 && prevval!=0)
                v.push_back({prev,it.first,prevval});
            prev = it.first;
            prevval = it.second;
        }
        return v;
    }
};