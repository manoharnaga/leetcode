class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> a(26,0);
        for(string s: words){
            for(char ch: s){
                a[ch-'a']++;
            }
        }
        int n = words.size();
        for(int i=0;i<26;i++){
            if(a[i]%n) return false;
        }
        return true;
    }
};