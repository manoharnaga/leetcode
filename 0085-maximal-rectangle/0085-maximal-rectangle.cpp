class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> height(m,0),left(m),right(m);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='1') height[j]++;
                else        height[j]=0;
            }
            stack<int> st;
            for(int j=0;j<m;j++){
                while(!st.empty() && height[st.top()]>=height[j]) st.pop();
                if(st.empty()) left[j] = -1;
                else           left[j] = st.top();
                st.push(j);
            }

            while(!st.empty()) st.pop();
            for(int j=m-1;j>=0;j--){
                while(!st.empty() && height[st.top()]>=height[j]) st.pop();
                if(st.empty()) right[j] = m;
                else           right[j] = st.top();
                st.push(j);
            }

            for(int j=0;j<m;j++){
                int val = height[j] * (right[j]-1-(left[j]+1)+1);
                ans = max(ans,val);
            }
        }
        return ans;
    }
};