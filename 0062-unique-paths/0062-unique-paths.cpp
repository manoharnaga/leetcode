class Solution {
public:
    int uniquePaths(int m, int n) {
        double res = 1.0;
        for(int i=1,j=n;i<=(m-1);i++,j++){
            res = (res * j)/i;
        }
        return (int)res;
    }
};