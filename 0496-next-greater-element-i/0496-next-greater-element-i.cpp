class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<int> nge(n),ans;
        stack<int> st;
        st.push(b[n-1]);
        nge[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=b[i]) st.pop();
            if(st.empty()){
                nge[i] = -1;
            }
            else{
                nge[i] = st.top();
            }
            st.push(b[i]);
        }
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[b[i]]=i;
        
        for(int i=0;i<a.size();i++){
            ans.push_back(nge[mp[a[i]]]);
        }
        return ans;
    }
};