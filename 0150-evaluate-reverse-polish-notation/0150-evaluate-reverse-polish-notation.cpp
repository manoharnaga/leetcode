#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        stack<char> st2;
        for(string s: tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                if(s=="+")      st.push(val2+val1);
                else if(s=="-") st.push(val2-val1);
                else if(s=="*") st.push(val2*val1);
                else if(s=="/") st.push(val2/val1);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};