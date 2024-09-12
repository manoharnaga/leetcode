class Solution {
public:
    typedef long long ll;
    long long findMaximumScore(vector<int>& a) {
        int n = a.size();
        vector<ll> dp(n,0);
        vector<int> nge(n,n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            // equal condition remember - remove or present!
            while(!st.empty() && a[st.top()]<=a[i]) st.pop();
            if(st.empty()) nge[i] = n-1;
            else           nge[i] = st.top();
            st.push(i);
        }
        // for(int i=0;i<n;i++) cout<<nge[i]<<' ';
        // cout<<"\n";
        int i=0;
        ll ans = 0;
        while(i<n-1){
            // cout<<i<<" "<<ans<<"\n";
            ans += ((ll)nge[i]-i)*a[i];
            i = nge[i];
        }
        // if(i==0 and nge[i]==n) ans = ((ll)n-1)*a[0];
        return ans;
    }
};