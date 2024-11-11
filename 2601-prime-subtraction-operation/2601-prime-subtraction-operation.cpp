class Solution {
public:
    vector<int> p;
    
    void getPrimes(int n){
        vector<int> vist(n+1,1);
        vist[0]=vist[1]=0;
        for(int i=2;i<=n;i++){
            if(vist[i]){
                for(int j=2*i;j<n;j+=i) vist[j]=0;
            }
        }
        for(int i=0;i<=n;i++){
            if(vist[i]) p.push_back(i);
        }
    }
    
    bool primeSubOperation(vector<int>& a) {
        getPrimes(1000);
        int n = a.size();
        
        for(int i=n-2;i>=0;i--){
            if(a[i]>=a[i+1]){
                int f = 0;
                for(int j=0;j<p.size() && p[j]<a[i];j++){
                    if((a[i]-p[j])<a[i+1]){
                        a[i] -= p[j];
                        f = 1;
                        break;
                    }
                }
                // if(!f) cout<<i<<" "<<a[i]<<"\n";
                if(!f) return false;
            }
        }
        return true;
    }
};