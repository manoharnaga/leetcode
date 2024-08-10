class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        if(n==1) return a[0];
        
        vector<int> nse1(n),nse2(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(st.empty()){
                nse1[i] = -1;
            }
            else{
                nse1[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(st.empty()){
                nse2[i] = n;
            }
            else{
                nse2[i] = st.top();
            }
            st.push(i);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,a[i]*(nse2[i]-1-nse1[i]-1+1));
        }
        return ans;
    }
};