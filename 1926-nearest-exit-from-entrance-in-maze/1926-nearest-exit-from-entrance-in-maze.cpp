class Solution {
public:
    int nearestExit(vector<vector<char>>& a, vector<int>& e) {
        // level order traversal
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        q.push({e[0],e[1]});
        a[e[0]][e[1]] = '+';
        int moves = -1;
        while(!q.empty()){
            int sz = q.size();
            moves++;
            for(int k=0;k<sz;k++){
                auto [x,y] = q.front();
                q.pop();
                for(auto it: dir){
                    int i = x+it[0];
                    int j = y+it[1];
                    if(i<0 || j<0 || i==n || j==m){
                        if(x!=e[0] || y!=e[1]) return moves;
                    }
                    else if(a[i][j]=='.'){
                        a[i][j] = '+';
                        q.push({i,j});
                    }
                }
            }
        }
        return -1;
    }
};