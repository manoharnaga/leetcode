#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;

    ll gcd(ll x, ll y)
    {
        ll a = max(x, y);
        ll b = min(x, y);
        while (b > 0)
        {
            ll temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ll lcm_val(ll x, ll y)
    {
        ll val = x * y;
        ll gcdval = gcd(x, y);
        val /= gcdval;
        return val;
    }
    
    string fractionAddition(string s) {
        int neg = 1;
        vector<int> num,den;
        string numf,denf;
        int f = 0;
        int lcmval = 1;
        if(s[0]=='-') neg = -1;

        for(int i=0;i<=s.size();i++){
            if(i==s.size() || s[i]=='+' || s[i]=='-'){
                if(i==0) continue;
                // cout<<numf<<" "<<denf<<"\n";
                int numval = stoi(numf);
                int denval = stoi(denf);
                num.push_back(neg*numval);
                den.push_back(denval);
                lcmval = lcm_val((ll)lcmval,(ll)denval);

                numf = "";
                denf = "";
                f = 0;

                if(s[i]=='-') neg = -1;
                else          neg = 1;
            }
            else if(s[i]=='/'){
                f = 1;
            }
            else{
                if(!f) numf+=s[i];
                else   denf+=s[i];
            }
        }
        int sum = 0;
        for(int i=0;i<num.size();i++){
            // cout<<(num[i]*(lcmval/den[i]))<<" "<<den[i]<<"\n";
            sum += (num[i]*(lcmval/den[i]));
        }
        // cout<<sum<<" "<<lcmval<<" 1\n";
        // sum/lcmval
        for(int i=2;i<=lcmval;i++){
            while(sum%i==0 && lcmval%i==0){
                sum/=i;
                lcmval/=i;
            }
        }
        // cout<<sum<<" "<<lcmval<<" 2\n";
        
        string ans;
        ans += to_string(sum);
        ans += "/";
        ans += to_string(lcmval);
        return ans;
    }
};