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
                int val = 0,mult=1;
                while(!st.empty() && st.top()>='0' && st.top()<='9'){
                    val = val + mult*(st.top()-'0');
                    mult *= 10;
                    st.pop();
                }
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