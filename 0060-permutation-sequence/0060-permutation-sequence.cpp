class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        int fact = 1;
        for(int i=1;i<n;i++) fact*=i;
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        k = k-1;
        while(1){
            int idx = k/fact;
            ans += to_string(v[idx]);
            v.erase(v.begin()+idx);
            if(v.empty()) break;
            
            k = k%fact;
            fact = fact/v.size();
        }
        return ans;
    }
};