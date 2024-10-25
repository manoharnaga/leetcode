class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& ev) {
        int n =  ev.size();
        sort(ev.begin(),ev.end(),[](const auto& x,const auto& y){
            return (x[0]==y[0] ? x[1]>y[1] : x[0]<y[0]);
        });
        vector<int> v;
        for(auto& p: ev){
            InsertLIS(v,p[1]);
        }
        int res = (int)v.size();
        return res;
    }
    
    void InsertLIS(vector<int>& v,int y){
        auto it = lower_bound(v.begin(),v.end(),y);
        if(it==v.end()) v.push_back(y);
        else            *it = y;
    }
};