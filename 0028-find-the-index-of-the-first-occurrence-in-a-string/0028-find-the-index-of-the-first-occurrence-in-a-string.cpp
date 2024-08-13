class Solution {
public:
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }

    int strStr(string haystack, string needle) {
        string total = needle;
        total += "#";
        total += haystack;
        vector<int> pi = prefix_function(total);
        int n = needle.size();
        for(int i=0;i<total.size();i++){
            if(pi[i]==n){
                return (i-(n+1)-(n-1));
            }
        }
        return -1;
    }
};