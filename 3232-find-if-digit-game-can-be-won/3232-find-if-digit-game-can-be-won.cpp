class Solution {
public:
    bool canAliceWin(vector<int>& a) {
        int sum = 0;
        int x1 = 0,x2 = 0;
        for(int val: a){
            sum+=val;
            if(!(val/10)){
                x1 += val;
            }
            else x2+=val;
        }
        return (x1>(sum-x1) || x2>(sum-x2));
    }
};