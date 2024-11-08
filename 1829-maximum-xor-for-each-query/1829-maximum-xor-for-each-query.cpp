class Solution {
public:
    vector<int> getMaximumXor(vector<int>& a, int maximumBit) {
        int xorval = 0;
        for(int val: a) xorval^=val;
        int n = a.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            int k = 0;
            for(int j=0;j<maximumBit;j++){
                if(xorval & (1<<j)) continue;
                k+=(1<<j);
            }
            ans[n-i-1]=k;
            xorval^=a[i];
        }
        return ans;
    }
};