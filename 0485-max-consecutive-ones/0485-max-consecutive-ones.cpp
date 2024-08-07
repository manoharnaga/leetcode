class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int cnt = (a[0]==1);
        int ans = 0;
        for(int i=1;i<a.size();i++){
            if(a[i]!=1){
                ans = max(ans,cnt);
                cnt = 0;
                continue;
            }
            cnt++;
        }
        ans = max(ans,cnt);
        return ans;
    }
};