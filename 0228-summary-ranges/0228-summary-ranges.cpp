#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<string> summaryRanges(vector<int>& a) {
        int n = a.size();
        vector<string> ans;
        string x;
        int prev = 0;
        for(int i=0;i<n;i++){
            // ll x = 0;
            // if(i<n-1){
            //     x =
            // }
            if(i==n-1 || ((ll)a[i+1]-(ll)a[i])!=1ll){
                if(prev==i){
                   x = to_string(a[i]);
                }
                else{
                    x = to_string(a[prev]);
                    x += "->";
                    x += to_string(a[i]);
                }
                ans.push_back(x);
                prev = i+1;
            }
        }
        return ans;
    }
};