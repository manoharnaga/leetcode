class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int idx = 0;
        int sz = INT_MAX;
        for(string s: strs) sz = min(sz,(int)s.size());
        
        char ch;
        int f = 1;
        // cout<<sz<<"\n";
        while(idx<sz && f){
            for(int i=1;i<strs.size();i++){
                if(strs[i-1][idx]!=strs[i][idx]){
                    f = 0;
                    break;
                }
            }
            if(f) ans+=strs[0][idx];
            idx++;
        }
        
        return ans;
    }
};