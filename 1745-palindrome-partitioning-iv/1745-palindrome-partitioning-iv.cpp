class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> ispal(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(s[i]==s[j] && ((j-i)<2 || ispal[i+1][j-1])){
                    ispal[i][j] = 1;
                }
            }
        }

        for(int i=0;i<n-1;i++){
            for(int j=0;j<i;j++){
                if(ispal[0][j] && ispal[j+1][i] && ispal[i+1][n-1]){
                    return true;
                }
            }
        }
        return false;
    }
};