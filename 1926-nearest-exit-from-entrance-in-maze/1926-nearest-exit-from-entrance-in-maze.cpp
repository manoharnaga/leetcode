class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int,int>> q;
        q.push({e[0],e[1]});
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        int moves = 1;
        maze[e[0]][e[1]] = '+';
        while(!q.empty()){
            int sz = q.size();
            // all nodes in cur level
            for(int i=0;i<sz;i++){
                auto [h1,h2] = q.front();
                q.pop();
                for(int l=0;l<4;l++){
                    int x = h1+dir[l][0];
                    int y = h2+dir[l][1];
                    if(x<0 || x>=n || y<0 || y>=m || maze[x][y]=='+') continue; 
                    if(x==0 || y==0 || x==(n-1) || y==(m-1)) return moves;

                    maze[x][y] = '+';
                    q.push({x,y});
                }
            }
            // at each level increase moves
            moves++;
        }
        return -1;
    }
};