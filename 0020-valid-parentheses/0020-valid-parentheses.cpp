class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s){
            if(st.empty()){
                st.push(ch);
            }
            else{
                if(ch=='[' || ch=='(' || ch=='{'){
                    st.push(ch);
                }
                else{
                    if(st.top()=='(' && ch==')' 
                       || st.top()=='[' && ch==']'
                      || st.top()=='{' && ch=='}'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};