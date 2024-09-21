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

    string shortestPalindrome(string s) {
        string t;
        t = s;
        reverse(s.begin(),s.end());
        t += "#";
        t += s;
        vector<int> pi = prefix_function(t);
        int idx = pi.back();
        reverse(s.begin(),s.end());
        string h = s.substr(idx);
        reverse(h.begin(),h.end());
        h+=s;
        return h;
    }
};