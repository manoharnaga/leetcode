class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> ispal(n,vector<int>(n,0));
        
        int d[n];
        for(int i=n-1;i>=0;i--){
            d[i] = n-i-1;
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<2 || ispal[i+1][j-1])){
                    ispal[i][j] = 1;
                    if(j==n-1){
                        d[i] = 0;
                    }
                    else d[i] = min(d[i],1+d[j+1]);
                }
            }
        }
        return d[0];
    }
};