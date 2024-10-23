class Solution {
public:
    int moves[17][17], dp[17][32767] = {};
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
int dfs(int i, unsigned int mask, int turns, int sz) {
    if (turns == sz)
        return 0;
    if (dp[i][mask] == 0) {
        dp[i][mask] = turns % 2 ? INT_MAX : 0;
        for (int j = 0; j < sz; ++j)
            if (((1 << j) & mask) == 0) {
                int resj = moves[i][j] + dfs(j, mask + ((1 << j)), turns + 1, sz);
                dp[i][mask] = turns % 2 ?  min(dp[i][mask], resj) : max(dp[i][mask], resj);
            }
    }
    return dp[i][mask];
}
int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
    positions.push_back({kx, ky});
    for (int i = 0; i < positions.size(); ++i)
        bfs(i, positions);
    return dfs(positions.size() - 1, 0, 0, positions.size() - 1);
}
};