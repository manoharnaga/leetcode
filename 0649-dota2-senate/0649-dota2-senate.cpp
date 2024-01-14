class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> rq,dq;
        for(int i=0;i<n;i++){
            if(senate[i] == 'R'){
                rq.push(i);
            }
            else{
                dq.push(i);
            }
        }
        while(!rq.empty() && !dq.empty()){
            int x = rq.front();
            int y = dq.front();
            rq.pop();
            dq.pop();
            if(x>y){
                dq.push(y+n);
            }
            if(x<y){
                rq.push(x+n);
            }
        }
        string ans;
        if(rq.size() > dq.size()) ans = "Radiant";
        else                      ans = "Dire";
        return ans;
    }
};