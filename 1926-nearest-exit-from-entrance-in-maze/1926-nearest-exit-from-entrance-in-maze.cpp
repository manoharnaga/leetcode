class Solution {
public:
    int nearestExit(vector<vector<char>>& a, vector<int>& e) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<pair<int,int>,int>> q;
        q.push({{e[0],e[1]},0});
        a[e[0]][e[1]] = '+';
        while(!q.empty()){
            auto [x,y] = q.front().first;
            int moves = q.front().second;
            q.pop();
            for(auto it: dir){
                int i = x+it[0];
                int j = y+it[1];
                if(i<0 || j<0 || i==n || j==m){
                    if(x!=e[0] || y!=e[1])  return moves;
                }
                else if(a[i][j]=='.'){  
                    a[i][j] = '+';
                    q.push({{i,j},moves+1});
                }
            }
        }
        return -1;
    }
};