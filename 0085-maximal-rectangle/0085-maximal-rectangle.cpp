class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        vector<int> right(m),left(m),height(m);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1') height[j]++;
                else               height[j] = 0;
            }
            // largest rectangle in a histogram
            // nse
            stack<int> st;
            for(int j=0;j<m;j++){
                while(!st.empty() && height[st.top()]>=height[j]) st.pop();
                if(st.empty()) left[j]=-1;
                else           left[j] = st.top();
                st.push(j);
            }
            while(!st.empty()) st.pop();
            for(int j=m-1;j>=0;j--){
                while(!st.empty() && height[st.top()]>=height[j]) st.pop();
                if(st.empty()) right[j]=m;
                else           right[j]=st.top();
                st.push(j);
            }
            // for(int j=0;j<m;j++) cout<<height[j]<<" ";
            // cout<<"\n";
            
            for(int j=0;j<m;j++){
                int val = height[j]*(right[j]-1-(left[j]+1)+1);
                // cout<<val<<" ";
                ans = max(ans,val);
            }
            // cout<<"\n";
        }
        return ans;
    }
};