#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(),items.end(),[](const auto& x,const auto& y){
            if(x[0]==y[0]) return x[1]>y[1];
            return x[0]<y[0];
        });
        vector<int> v(n);
        v[0]=items[0][1];
        for(int i=1;i<n;i++) v[i]=max(v[i-1],items[i][1]);
        
        // for(auto it: items) cout<<it[0]<<it[1]<<"\n";
        
        vector<int> ans;
        for(int x: queries){
            vector<int> search = {x-1,INT_MAX};
            int idx = lower_bound(items.begin(),items.end(),search)-items.begin();
            // cout<<idx<<"kk\n";
            if(idx==0 && items[idx][0]>x){
                ans.push_back(0);
            }
            else{
                if(idx==n || items[idx][0]>x) ans.push_back(v[idx-1]);
                else                          ans.push_back(v[idx]);
            }
        }
        return ans;
    }
};