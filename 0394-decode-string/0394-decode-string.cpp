class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(char ch: s){
            if(ch==']'){
                string temp;
                while(st.top()!='['){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                string x;
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    x+=st.top();
                    st.pop();
                }
                reverse(x.begin(),x.end());
                int val = stoi(x);
                for(int i=0;i<val;i++){
                    for(int j=temp.size()-1;j>=0;j--){
                        st.push(temp[j]);
                    }
                }
            }
            else{
                st.push(ch);
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};