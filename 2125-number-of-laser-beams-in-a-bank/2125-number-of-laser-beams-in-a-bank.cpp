class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        for(char ch: bank[0]){
            prev += (ch=='1');
        }
        int ans = 0;
        for(int i=1;i<bank.size();i++){
            int cur = 0;
            for(char ch: bank[i]){
                cur += (ch=='1');
            }
            if(cur>0){
                ans += cur*prev;
                prev = cur;
            }
        }
        return ans;
    }
};