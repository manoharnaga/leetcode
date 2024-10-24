class Solution {
public:
    
    int v1[129],v2[129];
    int d1[129][410][210] = {};
    int d2[129][410][210] = {};
    void dfs1(int cur,vector<int>& a,int k,int idx,int n){
        if(k==0){
            v1[cur] = min(v1[cur],idx-1);
            d1[cur][idx-1][k] = 1;
            return;
        }
        if(idx<n && d1[cur][idx][k]==0){
            d1[cur][idx][k] = 1;
            dfs1(cur|a[idx],a,k-1,idx+1,n);
            dfs1(cur,a,k,idx+1,n);
        }
    }
    
    void dfs2(int cur,vector<int>& a,int k,int idx){
        if(k==0){
            v2[cur] = max(v2[cur],idx+1);
            d2[cur][idx+1][k] = 1;
            return;
        }
        if(idx>=0 && d2[cur][idx][k]==0){
            d2[cur][idx][k] = 1;
            dfs2(cur|a[idx],a,k-1,idx-1);
            dfs2(cur,a,k,idx-1);
        }
    }
    
    int maxValue(vector<int>& a, int k) {
        int n = a.size();
        for(int i=0;i<128;i++) v1[i] = n+10;
        for(int i=0;i<128;i++) v2[i] = 0;
        dfs1(0,a,k,0,n);
        dfs2(0,a,k,n-1);
        int res = 0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<128;j++){
                d1[j][i][0] = d1[j][i][0] || d1[j][i-1][0];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<128;j++){
                d2[j][i][0] = d2[j][i][0] || d2[j][i+1][0];
            }
        }
        
        for(int p=1;p<n;p++){
            for(int i=0;i<128;i++){
                for(int j=0;j<128;j++){
                    int h1 = d1[i][p-1][0];
                    int h2 = d2[j][p][0];
                    if(h1 && h2)
                        res = max(res,i^j);
                }
            }
        }
        // for(int i=0;i<128;i++){
        //     for(int j=0;j<128;j++){
        //         if(v1[i]<v2[j]){
        //             res = max(res,i^j);
        //         }
        //     }
        // }
        return res;
    }
};