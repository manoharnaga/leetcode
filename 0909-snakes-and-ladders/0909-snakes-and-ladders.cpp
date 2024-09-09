class Solution {
public:
    pair<int,int> getCoord(int x,int n){
        int i = (x-1)/n;
        int j = (x-1)%n;
        if(i%2){
            j = n-1-j;
        }
        return {n-i-1,j};
    }
    
    int snakesAndLadders(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> vist(n*n+1,0);
        
        queue<pair<int,int>> q;
        q.push({1,0});
        vist[1] = 1;
        int ans = INT_MAX;
        while(!q.empty()){
            int sz = q.size();
            for(int k=0;k<sz;k++){
                auto [x,moves] = q.front();
                if(x==(n*n)){
                    ans = min(ans,moves);
                }
                q.pop();
                for(int dice=1;dice<=6;dice++){
                    int x2 = x+dice;
                    if(x2>(n*n)) continue;
                    if(x2==(n*n)){
                        vist[x2] = 1;
                        ans = min(ans,1+moves);
                    }
                    auto [i,j] = getCoord(x2,n);
                    if(a[i][j]!=-1){
                        if(!vist[a[i][j]]){
                            vist[a[i][j]] = 1;
                            q.push({a[i][j],1+moves});
                        }
                    }
                    else{
                        if(!vist[x2]){
                            vist[x2] = 1;
                            q.push({x2,1+moves});
                        }
                    }
                }
            }
        }
        return (ans==INT_MAX ? -1: ans);
    }
};