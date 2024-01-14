class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a1(26,0),a2(26,0);
        for(char ch: word1){
            a1[ch-'a']++;
        }
        for(char ch: word2){
            a2[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if((a1[i] && !a2[i]) || (!a1[i] && a2[i])){
                return false;
            }
        }
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        return (a1==a2);
    }
};