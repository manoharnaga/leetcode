class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        int i = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int j=0;j<s.size() && i<g.size();j++){
            if(s[j]>=g[i]){
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};