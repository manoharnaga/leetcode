class Solution {
public:
    int ans;
    void rec(vector<pair<int,int>>& q,int i,int n){
        if(i==n){
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            int f = 1;
            for(auto [p,q]: q){
                if(i==p || j==q || (i+j)==(p+q) || (i-j)==(p-q)){
                    f = 0;
                    break;
                }
            }
            if(!f) continue;
            q.push_back({i,j});
            rec(q,i+1,n);
            q.pop_back();
        }
    }
    int totalNQueens(int n) {
        vector<pair<int,int>> q;
        ans = 0;
        rec(q,0,n);
        return ans;
    }
};