class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int j = 31;
        for(uint32_t i=0,j=31;i<32;i++,j--){
            if((n>>i) & 1){
                ans += (1<<j);
            }
        }
        return ans;
    }
};