#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        for(int i=1;i<n;i++){
            // while(i<n && path[i]=='/') i++;
            string x;
            while(i<n && path[i]!='/'){
                x += path[i++];
            }
            if(x.empty() || x==".") continue;

            if(x==".."){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(x);
            }
        }
        vector<string> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        string ans;
        for(string s: v){
            ans += "/";
            ans += s;
        }
        if(ans.empty()) ans="/";
        return ans;
    }
};