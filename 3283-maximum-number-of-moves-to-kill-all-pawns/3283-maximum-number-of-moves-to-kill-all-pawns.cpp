class Solution {
public:
    int dp[17][32767];
    int moves[17][17];
    int n;
    
    int knight[9] = {1, 2, 1, -2, -1, 2, -1, -2, 1}; 

    void bfs(int i, vector<vector<int>> &pos) {
        int b[50][50] = {}, sx = pos[i][0], sy = pos[i][1];
        vector<pair<int, int>> q{{sx, sy}};
        while (!q.empty()) {
            vector<pair<int, int>> q1;
            for (auto [x, y] : q)
                for (int d = 0; d + 1 < 9; ++d) {
                    int dx = x + knight[d], dy = y + knight[d + 1];
                    if (min(dx, dy) >= 0 && max(dx, dy) < 50 && !(dx == sx && dy == sy) && b[dx][dy] == 0) {
                        b[dx][dy] = b[x][y] + 1;
                        q1.push_back({dx, dy});
                    }
                }
            swap(q, q1);
        }
        for (int j = i + 1; j < pos.size(); ++j)
            moves[i][j] = moves[j][i] = b[pos[j][0]][pos[j][1]];        
    }

    int func(int kx,int ky,int x,int y){
        // if(kx<0 || ky<0 || kx==50 || ky==50) return INT_MAX;
        
        int vist[50][50] = {};
        
        vector<vector<int>> dir = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
        vector<pair<int,int>> q;
        q.push_back({kx,ky});
        int moves = 0;
        while(!q.empty()){
            vector<pair<int,int>> q1;
            moves++;
            for(auto& [hx,hy]: q){
                for(auto& it: dir){
                    int nx = hx+it[0];
                    int ny = hy+it[1];
                    if(nx<0 || ny<0 || nx>=50 || ny>=50 || vist[nx][ny]) continue;
                    if(nx==x && ny==y) return moves;
                    vist[nx][ny] = 1;
                    q1.push_back({nx,ny});
                }
            }
            swap(q,q1);
        }
        return 0;
    }
    
    int rec(int idx,int turn,int pawns,int mask){
        if(pawns==0) return 0;
        
        if(dp[idx][mask]!=-1) return dp[idx][mask];
        
        int maxval = 0,minval = INT_MAX;
        for(int i=0;i<n-1;i++){
            if(((1<<i) & mask) == 0){
                int ret = moves[idx][i]+rec(i,!turn,pawns-1,mask+(1<<i));
                if(turn==0) maxval = max(maxval,ret);
                else        minval = min(minval,ret);
            }
        }
        
        return dp[idx][mask] = (turn ? minval: maxval);
    }
    
    int maxMoves(int kx, int ky, vector<vector<int>>& pos) {
        pos.push_back({kx,ky});
        n = pos.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                moves[i][j] = moves[j][i] = func(pos[i][0],pos[i][1],pos[j][0],pos[j][1]);
            }
        }
        // for(int i=0;i<n;i++) bfs(i,pos);
        return rec(n-1,0,n-1,0);
    }
};