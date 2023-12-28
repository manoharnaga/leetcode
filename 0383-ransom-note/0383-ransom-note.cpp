class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26],b[26];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(char ch: ransomNote) a[ch-'a']++;
        for(char ch: magazine) b[ch-'a']++;
        for(int i=0;i<26;i++){
            if(b[i]<a[i]) return false;
        }
        return true;
    }
};