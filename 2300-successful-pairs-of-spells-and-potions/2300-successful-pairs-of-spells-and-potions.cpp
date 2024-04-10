class Solution {
public:
    typedef long long ll;
    #define MOD 1000000007
    int bin(vector<int>& a,int b,ll x){
        int n = a.size();
        int low = 0;
        int high = n-1;
        ll c = b;
        int ans = 0;
        while(low<=high){
            int mid = (high-low)/2 + low;
            ll val = a[mid]*c;
            if(val>=x){
                ans = max(ans,(n-mid));
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        sort(potions.begin(),potions.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
          ans[i] = bin(potions,spells[i],success);
        }
        return ans;
    }
};