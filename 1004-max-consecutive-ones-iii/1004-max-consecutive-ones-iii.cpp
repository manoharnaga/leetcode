class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int n = a.size();
        int s=0,e=0;
        int ans = 0;
        while(e<n){
            if(!a[e]){
                while(s<=e && k<=0){
                    if(!a[s]){
                        k++;
                    }
                    s++;
                }
                k--;
            }
            ans = max(ans,(e-s+1));
            e++;
        }
        return ans;
    }
};