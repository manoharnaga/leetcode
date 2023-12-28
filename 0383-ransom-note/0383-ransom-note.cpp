class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26];
        memset(a,0,sizeof(a));
        for(char ch: magazine) a[ch-'a']++;
        
        for(char ch: ransomNote){
            if(a[ch-'a']==0) return false;
            a[ch-'a']--;
        }
        return true;
    }
};