class Solution {
public:
    struct Node{
        int parent;
        int rank;
        Node(){
            parent = -1;
            rank = 0;
        }
    };
    
    int find(int v,vector<Node>& p){
        if(p[v].parent==-1) return v;
        return p[v].parent = find(p[v].parent,p);
    }
    
    void union_op(int x,int y,vector<Node>& dsuf){
        int apx = find(x,dsuf);
        int apy = find(y,dsuf);
        if(apx==apy) return;
        
        if(dsuf[apx].rank>dsuf[apy].rank){
            dsuf[apy].parent = apx;
        }
        else if(dsuf[apx].rank<dsuf[apy].rank){
            dsuf[apx].parent=apy;
        }
        else{
            dsuf[apx].parent=apy;
            dsuf[apx].rank+=1;
        }
    }
    
    int largestComponentSize(vector<int>& a) {
        int n = a.size();
        int x = *max_element(a.begin(),a.end());
        vector<Node> dsuf(x+1);
        
        for(int i=0;i<n;i++){
            int y = a[i];
            for(int j=2;j*j<=y;j++){
                if(y%j==0){
                    int k = j;
                    union_op(j,y,dsuf);
                    union_op(y/j,y,dsuf);
                }
            }
        }
        int cnt = 0;
        map<int,int> mp;
        for(int val: a){
            mp[find(val,dsuf)]++;
        }
        int ans = 0;
        for(auto& it: mp) ans = max(ans,it.second);
        return ans;
    }
};