class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for(int i=0;i<30;i++){
            int b1 = (start>>i) & 1;
            int b2 = (goal>>i) & 1;
            cnt += (b1!=b2);
        }
        return cnt;
    }
    int minOperations(vector<int>& a, int k) {
        int start  = 0;
        for(int val: a) start ^= val;
        return minBitFlips(start,k);
    }
};