class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> ngel(n,-1),nger(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]<=a[i]) st.pop();
            if(st.empty()){
                ngel[i] = -1;
            }
            else{
                ngel[i] = st.top();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]<=a[i]) st.pop();
            if(st.empty()){
                nger[i] = -1;
            }
            else{
                nger[i] = st.top();
            }
            st.push(i);
        }
        // for(int val: ngel) cout<<val<<" ";
        // cout<<"\n";
        // for(int val: nger) cout<<val<<" ";
        // cout<<"\n";
        int ans = 0;
        set<vector<int>> s;
        for(int i=0;i<n;i++){
            if(ngel[i]!=-1 && nger[i]!=-1 && s.find({a[i],ngel[i],nger[i]})==s.end()){
                int x = min(a[ngel[i]],a[nger[i]]);
                ans += (x-a[i])*(nger[i]-ngel[i]-1);
                s.insert({a[i],ngel[i],nger[i]});
            }
        }
        return ans;
    }
};