class Solution {
public:
    typedef long long ll;
    long long countFairPairs(vector<int>& a, int lower, int upper) {
        int n = a.size();
        sort(a.begin(),a.end());
        for(int val: a) cout<<val<<" ";
        cout<<"\n";

        ll res = 0;
        for(int i=0;i<n;i++){
            // before a[i]
            auto s = lower_bound(a.begin(),a.begin()+i,lower-a[i]);
            auto e = upper_bound(a.begin(),a.begin()+i,upper-a[i]);
            e--;
            res += max((e-s+1ll),0ll);
            // cout<<(e-s+1)<<"kk\n";
            // cout<<(e-a.begin())<<" "<<(s-a.begin())<<"idx1\n";
            // after a[i]
            s = lower_bound(a.begin()+i+1,a.end(),lower-a[i]);
            e = upper_bound(a.begin()+i+1,a.end(),upper-a[i]);
            e--;
            res += max((e-s+1ll),0ll);

            // cout<<(e-s+1)<<"hh\n";
            // cout<<(e-a.begin())<<" "<<(s-a.begin())<<"idx2\n\n";
        }
        res = (res/2);
        return res;
    }
};