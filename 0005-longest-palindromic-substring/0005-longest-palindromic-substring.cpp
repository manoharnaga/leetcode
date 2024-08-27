class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> ispal(n,vector<int>(n,0));
        int start,end;
        start = end = 0;
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(s[i]==s[j] && ((j-i)<2 || ispal[i+1][j-1])){
                    if((j-i+1)>(end-start+1)){
                        start = i;
                        end = j;
                    }
                    ispal[i][j] = 1;
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};