class Solution {
public:
    int maximumGap(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        int diff = 0;
        for(int i=1;i<n;i++){
            diff = max(diff,a[i]-a[i-1]);
        }
        return diff;
    }
};