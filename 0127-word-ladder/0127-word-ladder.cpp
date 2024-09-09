class Solution {
public:
    int ham(string& x,string& y){
        int cnt = 0;
        for(int i=0;i<x.size();i++){
            if(x[i]!=y[i]) cnt++;
        }
        return cnt;
    }

    int ladderLength(string src, string dest, vector<string>& bank) {
        int m = bank.size();
        int idx = -1;
        for(int i=0;i<m;i++){
            if(bank[i]==dest){
                idx = i;
                break;
            }
        }
        if(idx==-1) return 0;

        vector<int> adj[m+1];

        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                if(ham(bank[i],bank[j])==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<m;i++){
            if(ham(src,bank[i])==1){
                adj[m].push_back(i);
                adj[i].push_back(m);
            }
        }

        vector<int> vist(m+1,0);
        queue<int> q;
        q.push(m);  
        vist[m] = 1;
        int moves = 0;
        while(!q.empty()){
            int sz = q.size();
            moves++;
            for(int i=0;i<sz;i++){
                int at = q.front();
                q.pop();
                if(at==idx) return moves;
                for(auto it: adj[at]){
                    if(!vist[it]){
                        vist[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
        return 0;
    }
};
