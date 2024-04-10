class Solution {
public:
    vector<string> ans;
    map<int,string> mp;
    void rec(string a,string x,int ind){
        if(ind>=a.size()){
            ans.push_back(x);
            return;
        }
        for(char ch: mp[a[ind]-'0']){
            rec(a,x+ch,ind+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return ans;
        ans.resize(0);
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string x="";
        rec(digits,x,0);
        return ans;
    }
};