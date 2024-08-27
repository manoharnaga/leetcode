class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int>> ispal(n,vector<int>(n,0));
        vector<pair<int,int>> v;
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(s[i]==s[j] && ((j-i)<2 || ispal[i+1][j-1])){
                    ispal[i][j] = 1;

                    if((j-i+1)>=k){
                        v.push_back({j,i});
                    }
                }
            }
        }
        sort(v.begin(),v.end());
        int cnt = 0;
        int prev = -1;
        for(auto it: v){
            if(it.second>prev){
                cnt++;
                prev = it.first;
            }
        }
        return cnt;
    }
};