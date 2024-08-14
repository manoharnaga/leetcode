class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> ispal(n,vector<int>(n,0));
        int ans = 0;
        pair<int,int> v;
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(s[i]==s[j] && (j-i<2 || ispal[i+1][j-1])){
                    ispal[i][j] = 1;
                    if(ans<(j-i+1)){
                        ans = j-i+1;
                        v = {i,j};
                    }
                }
            }
        }
        string h = s.substr(v.first,ans);
        return h;
    }
};