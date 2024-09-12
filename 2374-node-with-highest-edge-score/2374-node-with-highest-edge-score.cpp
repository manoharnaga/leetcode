class Solution {
public:
    typedef long long ll;
    int edgeScore(vector<int>& edges) {
        map<ll,ll> mp;
        for(int i=0;i<edges.size();i++){
            mp[(ll)edges[i]]+=i;
        }
        vector<vector<ll>> v;
        for(auto it: mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),[](const auto& x,const auto& y){
            if(x[0]==y[0]) return x[1]<y[1];
            return x[0]>y[0];
        });
        return v[0][1];
    }
};