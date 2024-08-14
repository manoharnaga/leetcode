class Solution {
public:
    bool isAnagram(string s, string t) {
       vector<int> a(26,0),b(26,0);
       for(char ch: s) a[ch-'a']++;
       for(char ch: t) b[ch-'a']++;
       return (a==b);
    }
};