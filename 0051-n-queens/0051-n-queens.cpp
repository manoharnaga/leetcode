class Solution {
public:
    vector<vector<string>> ans;
    int valid(vector<string>& q,int r,int c,int n){
        for(int i=0;i<n;i++) if(q[i][c]=='Q') return 0;
        for(int j=0;j<n;j++) if(q[r][j]=='Q') return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(abs(i-r)==abs(j-c) && q[i][j]=='Q') return 0;
            }
        }
        return 1;
    }
    void rec(vector<string>& q,int i,int n){
        if(i==n){
            ans.push_back(q);
            return;
        }
        for(int j=0;j<n;j++){
            if(valid(q,i,j,n)){
                q[i][j] = 'Q';
                rec(q,i+1,n);
                q[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        string temp = "";
        for(int i=0;i<n;i++) temp+=".";
        vector<string> q(n,temp);
        rec(q,0,n);
        return ans;
    }
};