class Solution {
public:
    int check(vector<int>& a,vector<int>& b){
        for(int i=0;i<26;i++){
            if(a[i]>b[i]) return 0;
        }
        return 1;
    }
    
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> alpha(26,0);
        for(char ch: allowed) alpha[ch-'a']=1;
        int cnt = 0;
        for(string s: words){
            vector<int> v(26,0);
            for(char ch: s) v[ch-'a']=1;
            cnt += check(v,alpha);
        }
        return cnt;
    }
};