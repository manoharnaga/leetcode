class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int k) {
        int n = a.size();
        vector<int> mx(n-k+1);
        
        deque<int> dq;
        for(int i=0;i<k;i++){
            while(!dq.empty() && a[dq.back()]<=a[i]) dq.pop_back();
            dq.push_back(i);
        }
        mx[0] = a[dq.front()];
        int j=1;
        for(int i=k;i<n;i++){
            while(!dq.empty() && a[dq.back()]<=a[i]) dq.pop_back();
            dq.push_back(i);
            if((i-k)==dq.front()) dq.pop_front();
            mx[j++] = a[dq.front()];
        }
        
        vector<int> len(n);
        for(int i=0;i<n;i++) a[i] = a[i]-i;
        len[0] = 1;
        for(int i=1;i<n;i++){
            len[i] = 1;
            if(a[i-1]==a[i]) len[i]+=len[i-1];
        }
        
        // for(int val: a) cout<<val<<" ";
        // cout<<"\n";
        // for(int val: len) cout<<val<<" ";
        // cout<<"\n";
        for(int i=k-1;i<n;i++){
            if(len[i]<k){
                mx[i-k+1] = -1;
            }
        }
        return mx;
    }
};