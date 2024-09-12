class Solution {
public:
    vector<int> frequencySort(vector<int>& a) {
        int n = a.size();
        map<int,int> mp;
        for(int val: a) mp[val]++;
        auto cmpfunc = [&mp](const auto& x,const auto& y){
            if(mp[x]==mp[y]) return x>y;
            return mp[x]<mp[y];
        };
        sort(a.begin(),a.end(),cmpfunc);
        return a;
    }
    
};