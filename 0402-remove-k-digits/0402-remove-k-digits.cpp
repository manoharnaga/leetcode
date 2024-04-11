class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(char ch: num){
            while(!ans.empty() && k && ans.back()>ch){
                ans.pop_back();
                k--;
            }
            if(ans.empty() && ch=='0') continue;
            ans.push_back(ch);
        }
        while(!ans.empty() && k--){
            ans.pop_back();
        }
        if(ans.empty()) return "0";
        return ans;
    }
};