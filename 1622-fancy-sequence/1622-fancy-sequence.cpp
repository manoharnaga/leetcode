
class Fancy {
public:
    typedef long long ll;
    ll a[100100];
    vector<vector<ll>> v;
    int n;
    ll add = 0;
    ll mult = 1;
    ll mod = 1e9+7;
    
    ll powermod(ll x,ll y){
        ll res = 1;
        ll a = x;
        while(y){
            if(y&1) res*=a;
            a*=a;
            a%=mod;
            res%=mod;
            y>>=1;
        }
        return res%mod;
    }
    
    Fancy() {
        n = 0;
    }
    
    void append(int val) {
        v.push_back({add,mult});
        a[n++] = val;
        // a[n++] = ((val-add+mod)%mod)*powermod(mult,mod-2)%mod;
    }
    
    void addAll(int inc) {
        add += inc;
        add %= mod;
        // cout<<add<<"\n";
    }
    
    void multAll(int m) {
        add *= m;
        add %= mod;
        mult *= m;
        mult %= mod;
        // cout<<mult<<"\n";
    }
    
    int getIndex(int idx) {
        if(idx>=n) return -1;
        ll res = a[idx];
        
        // cout<<idx<<"\n";
        // for(int i=0;i<v.size();i++) cout<<v[i][0]<<" ";
        // cout<<"\n";
        
        
        
        ll t1 = v[idx][0], t2 = v[idx][1];
        res -= t1;
        res = (res+mod)%mod;
        res = (res*powermod(t2,mod-2))%mod;   
        
        res *= mult;
        res %= mod;
        res += add;
        res %= mod;
        return res;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */