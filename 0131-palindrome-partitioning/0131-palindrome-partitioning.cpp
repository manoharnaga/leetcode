class Solution {
public:
    vector<vector<string>> ans;
    int isPalindrome(string s){
        int n = s.size();
        for(int i=0;i<(n/2);i++){
            if(s[i]!=s[n-i-1]) return 0;
        }
        return 1;
    }
    void rec(string s,vector<string>& v,int ind,int n){
        if(ind==n){
            if(isPalindrome(v.back())){
                ans.push_back(v);
            }
            return;
        }
        v[v.size()-1] += s[ind];
        rec(s,v,ind+1,n);
        v[v.size()-1].pop_back();
        
        if(isPalindrome(v.back())){
            string s2 = "";
            s2 += s[ind];
            v.push_back(s2);
            rec(s,v,ind+1,n);
            v.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> v = {s.substr(0,1)};
        rec(s,v,1,n);
        return ans;
    }
};