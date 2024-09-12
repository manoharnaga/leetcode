class Solution {
public:
    int similarPairs(vector<string>& words) {
        for(string& s: words){
            vector<int> alpha(26,0);
            string x;
            for(char ch: s) alpha[ch-'a']=1;
            for(int i=0;i<26;i++){
                if(alpha[i]){
                    char k = i+'a';
                    x+=k;
                }
            }
            s = x;
        }
        int cnt = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(words[i]==words[j]) cnt++;
            }
        }
        return cnt;
    }
};