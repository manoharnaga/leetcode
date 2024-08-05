class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        sort(a.begin(),a.end());
        if(a.empty()) return 0;
        int cnt = 1;
        int ans = 1;
        for(int i=1;i<a.size();i++){
            if(a[i-1]==a[i]) continue;
            if((a[i-1]+1)!=a[i]){
                ans = max(ans,cnt);
                cnt = 0;
            }
            cnt++;
        }
        ans = max(ans,cnt);
        return ans;
    }
};