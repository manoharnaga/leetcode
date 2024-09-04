class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> dir = {{1,0},{0,-1},{-1,0},{0,1}};
        int cur_dir = 3;
        int x,y;
        x = y = 0;
        set<vector<int>> obs;
        for(auto it: obstacles) obs.insert(it);
        // if(obs.find({x,y})!=obs.end()) return 0;
        int m = 4;
        int ans = 0;
        for(int i=0;i<commands.size();i++){
            int cmd = commands[i];
            if(cmd==-1){
                cur_dir = (cur_dir+1)%m;
            }
            else if(cmd==-2){
                cur_dir = (cur_dir-1+m)%m;
            }
            else{
                for(int k=1;k<=cmd;k++){
                    int new_x = x+dir[cur_dir][0];
                    int new_y = y+dir[cur_dir][1];
                    if(obs.find({new_x,new_y})!=obs.end()){
                        break;
                    }
                    x = new_x;
                    y = new_y;
                    ans = max(ans,(x*x+y*y));
                }
            }
        }
        return ans;
    }
};