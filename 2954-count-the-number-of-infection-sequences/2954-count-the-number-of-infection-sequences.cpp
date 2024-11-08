class Solution {
public:
    typedef long long ll;
    const int mod = 1e9+7;
    const int N = 1e5;
    ll fact[(int)1e5+10];
    void preprocess(){
        fact[0]=1ll;
        for(ll i=1;i<=N;i++){
            fact[i] = (fact[i-1]*i)%mod;
        }
    }
    
    ll powermod(ll x,ll y){
        ll res = 1, a = x;
        while(y>0){
            if(y & 1) res = (res*a)%mod;
            a = (a*a)%mod;
            y>>=1;
        }
        return res;
    }
    
    int numberOfSequence(int n, vector<int>& sick) {
        preprocess();
        vector<ll> lens;
        int m = sick.size();
        ll S = 0, k = 0;
        for(int i=0;i<m-1;i++){
            ll len = sick[i+1]-sick[i]-1;
            if(len>0){
                k += (len-1);
                lens.push_back(len);
            }
        }
        if(sick[0]>0)       lens.push_back(sick[0]);
        if(sick[m-1]<n-1)   lens.push_back(n-1-sick[m-1]);
        
        ll denom = 1;
        for(ll len: lens){
            denom = (denom*fact[len])%mod;
            S += (len);
            // cout<<len<<" ";
        }
        // cout<<"kk\n";
        // cout<<k<<" "<<S<<"\n";
        
        ll numer = fact[S];
        numer = (numer*powermod(2ll,k))%mod;
        numer = (numer*powermod(denom,mod-2))%mod;
        return numer;
    }
};