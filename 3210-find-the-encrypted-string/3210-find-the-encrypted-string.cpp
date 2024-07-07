class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        k %= n;
        string ans;
        for(int i=k;i<n;i++){
            ans+=s[i];
        }
        for(int i=0;i<k;i++) ans+=s[i];
        return ans;
    }
};