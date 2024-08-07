class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128,0);
        int i=0;
        int n = s.size();
        int ans = 0;
        for(int j=0;j<n;j++){
            while(i<=j && v[s[j]]){
                v[s[i]]--;
                i++;
            }
            v[s[j]]++;
            ans = max(ans,(j-i+1));
        }
        return ans;
    }
};