class Solution {
public:
    vector<vector<string>> ans;
    int valid(vector<string>& q,int r,int c,int n){
        for(int i=0;i<n;i++) if(q[i][c]=='Q') return 0;
        for(int j=0;j<n;j++) if(q[r][j]=='Q') return 0;
        int pr = r,pc = c;
        while(pr>=0 && pc>=0){
            if(q[pr][pc]=='Q') return 0;
            pr--;pc--;
        }
        pr = r;pc = c;
        while(pr<n && pc<n){
            if(q[pr][pc]=='Q') return 0;
            pr++;pc++;
        }
        pr = r;pc = c;
        while(pr<n && pc>=0){
            if(q[pr][pc]=='Q') return 0;
            pr++;pc--;
        }
        pr = r;pc = c;
        while(pr>=0 && pc<n){
            if(q[pr][pc]=='Q') return 0;
            pr--;pc++;
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