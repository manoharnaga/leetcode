class Solution {
public:
    vector<string> ans;
    void rec(string s,int n){
        if(n==0){
            ans.push_back(s);
            return;
        }
        if(s.back()=='0'){
            rec(s+"1",n-1);
        }
        else{
            rec(s+"0",n-1);
            rec(s+"1",n-1);
        }
    }
    vector<string> validStrings(int n) {
        ans.clear();
        string s;
        rec("0",n-1);
        rec("1",n-1);
        return ans;
    }
};