class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> vist(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto it = pq.top();
            int t = it[0], r = it[1], c = it[2];
            pq.pop();
            if(r==(m-1) && c==(n-1)) return t;
            if(vist[r][c]) continue;
            
            vist[r][c] = true;
            for(auto& dir: directions){
                int rr = r+dir[0];
                int cc = c+dir[1];
                if(rr<0 || cc<0 || rr==m || cc==n || vist[rr][cc]) continue;
                int wait = (grid[rr][cc]-t)%2==0;
                int tt = max(grid[rr][cc]+wait,t+1);
                pq.push({tt,rr,cc});
            }
        }
        return -1;
    }
};