class Solution {
public:
    int maximumTop(vector<int>& a, int k) {
        int n = a.size();
        if(k<=0) return a[0];
        if(n==1){
            if(k%2) return -1;
            else    return a[0];
        }
        if(k>=(n+1)) return *max_element(a.begin(),a.end());
        // int idx = (k==n) ? k-1: k;
        if(k==1) return a[1];
        
        if(k==n) *max_element(a.begin(),a.begin()+k-1);
        return max(*max_element(a.begin(),a.begin()+k-1),a[k]);
    }
};