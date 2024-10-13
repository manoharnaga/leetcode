class Solution {
public:
    int oddEvenJumps(vector<int>& a) {
        int n = a.size();
        vector<int> higher(n),lower(n);
        higher[n-1] = lower[n-1] = 1;
        map<int,int> mp;
        mp[a[n-1]] = n-1;
        int res = 1;
        for(int i=n-2;i>=0;i--){
            auto hi = mp.lower_bound(a[i]), lo = mp.upper_bound(a[i]);
            if(hi != mp.end()) higher[i] = lower[hi->second];
            if(lo != mp.begin()) lower[i] = higher[(--lo)->second];
            if(higher[i]) res++;
            
            mp[a[i]] = i;
        }
        return res;
    }
};