class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        int n = a.size();
        int res = 0,sum = 0,pref = 0;
        for(int i=0;i<n;i++){
            sum += i*a[i];
            pref += a[i];
        }
        pref -= a[n-1];
        // cout<<sum<<" "<<pref<<"\n";
        res = sum;
        int ptr = n-1;
        
        while(1){
            sum -= (n-1)*a[ptr];
            sum += pref;
            res = max(res,sum);
            if(ptr==0) break;
            pref = pref-a[ptr-1]+a[ptr];
            ptr--;
        }
        return res;
    }
};