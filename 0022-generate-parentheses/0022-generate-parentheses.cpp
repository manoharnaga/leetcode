class Solution {
public:
    int isValid(string& s){
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(!st.empty()) st.pop();
                else            return 0;
            }
        }
        return st.empty();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        n = 2*n;
        for(int b=0;b<(1<<n);b++){
            string p;
            for(int j=0;j<n;j++){
                if(b & (1<<j)) p+="(";
                else p+=")";
            }
            // cout<<p<<"\n";
            if(isValid(p)) ans.push_back(p);
        }
        return ans;
    }
};