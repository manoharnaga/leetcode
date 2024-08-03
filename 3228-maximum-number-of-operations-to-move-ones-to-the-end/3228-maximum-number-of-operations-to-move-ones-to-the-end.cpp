class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int one = -1;
        int zero = -1;
        int ans = 0,cnt = 0;
        int f = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(one==-1 || f) continue;
                zero = i;
                cnt += (zero-one);
                ans += cnt;
                one = -1;
                f=1;
            }
            else{
                if(one==-1) one=i;
                f=0;
            }
        }
        return ans;
    }
};