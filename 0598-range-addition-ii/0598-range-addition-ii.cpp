class Solution {
public:
    int maxCount(int n, int m, vector<vector<int>>& ops) {
        vector<int> row(n,0),col(m,0);
        for(auto it: ops){
            row[it[0]-1]++;
            col[it[1]-1]++;
        }
        for(int i=n-2;i>=0;i--) row[i] += row[i+1];
        for(int j=m-2;j>=0;j--) col[j] += col[j+1];
        int rcnt = 0,ccnt = 0;
        int temp = row[0];
        for(int i=0;i<n;i++){
            if(row[i]!=temp) break;
            rcnt++;
        }
        // temp = col[0];
        for(int i=0;i<m;i++){
            if(col[i]!=temp) break;
            ccnt++;
        }
        return rcnt*ccnt;
    }
};