class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0,ans=0;
        for(int val: gain){
            sum+=val;
            ans = max(ans,sum);
        }
        return ans;
    }
};