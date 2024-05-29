class Solution {
public:
    #define all(a) a.begin(),a.end()
    int func(string& x){
        int sign = 1,prev = 0;
        int val = 0;
        string y;
        cout<<x<<"\n";
        for(char ch: x){
            if(ch=='+' || ch=='-'){
                if(y.empty() && ch=='-'){
                    if(prev) sign=1;
                    else     sign=-1;
                    prev = 1;
                    continue;
                }
                val += sign*stoi(y);
                // cout<<val<<"x\n";
                y = "";
                if(ch=='+'){
                    sign=1;
                    prev = 0;
                }
                else{
                    if(prev) sign=1;
                    else     sign=-1;
                    prev = 1;
                }
            }
            else{
                prev = 0;
                y+=ch;
            }
        }
        // cout<<y<<"\n";
        if(!y.empty()) val += sign*stoi(y);
        return val;
    }
    int calculate(string s) {
        int n = s.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            if(s[i]==' ') continue;
            if(s[i]=='('){
                st.push("(");
            }
            else if(s[i]==')'){
                string x;
                while(st.top()!="("){
                    string y = st.top();
                    reverse(all(y));
                    x+=y;
                    st.pop();
                }
                st.pop();
                reverse(all(x));
                int val = func(x);
                cout<<to_string(val)<<"xy\n";
                st.push(to_string(val));
            }
            else{
                string x;
                x+=s[i];
                st.push(x);
            }
        }
        string x;
        while(!st.empty()){
            string y = st.top();
            reverse(all(y));
            // if(st.top()[0]=='-'){
            //     y.pop_back();
            //     y = "-"+y;
            // }
            x+=y;
            st.pop();
        }
        // cout<<"y\n";
        reverse(all(x));
        int ans = func(x);
        return ans;
    }
};