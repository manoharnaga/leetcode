class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i=s.size()-1;
        int j=0;
        while(j<i && s[j]==' ') j++;
        
        while(i>=j){
            while(i>=j && s[i]==' ') i--;
            string t;
            while(i>=j && s[i]!=' '){
                t+=s[i];
                i--;
            }
            reverse(t.begin(),t.end());
            ans+=t;
            ans+=' ';
        }
        ans.pop_back();
        return ans;
    }
};