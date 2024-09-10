class Solution {
public:
    typedef long long ll;
    long long totalCost(vector<int>& c, int k, int candidates) {
        int n = c.size();
        vector<int> vist(n,0);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int i=0,j=n-1;
        for(i=0;i<candidates;i++){
            vist[i] = 1;
            pq.push({c[i],i,+1});
        }
        i--;
        
        int f = 0;
        for(j=n-1;j>=(n-candidates);j--){
            if(vist[j]){
                j++;
                f = 1;
                break;
            }
            vist[j] = 1;
            pq.push({c[j],j,-1});
        }
        if(!f) j++;
        
        ll ans = 0;
        for(int p=0;p<k;p++){
            auto it = pq.top();
            pq.pop();
            ans += (ll)it[0];
            if(it[2]==1){
                i++;
                if(i<j) pq.push({c[i],i,1});
            }
            else{
                j--;
                if(i<j) pq.push({c[j],j,-1});
            }
        }
        return ans;
    }
};