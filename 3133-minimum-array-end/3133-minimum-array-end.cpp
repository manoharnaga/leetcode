class Solution {
public:
    typedef long long ll;
    long long minEnd(int N, int x) {
        ll n = N-1;
        ll res = x;
        vector<ll> v;
        for(ll j=0;j<63;j++){
            if(!(x & (1ll<<j))){
                v.push_back(j);
            }
        }
        
        for(ll i=0,k=0;i<32;i++,k++){
            if(n & (1ll<<i)){
                res = (res | (1ll<<v[k]));
            }
        }
        return res;
    }
};