class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(128,0),b(128,0);
        for(char ch: s) a[ch]++;
        for(char ch: t) b[ch]++;
        return (a==b);
    }
};