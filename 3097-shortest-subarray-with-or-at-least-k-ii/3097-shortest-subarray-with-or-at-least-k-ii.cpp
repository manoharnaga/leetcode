class Solution {
public:
    int getOr(vector<int>& v){
        int orval = 0;
        for(int i=30;i>=0;i--){
            if(v[i]>0) orval+=(1<<i);
        }
        return orval;
    }
    
    void update(vector<int>& v,int x,int one){
        for(int i=0;i<31;i++){
            if((x>>i) & 1) v[i]+=one;
        }
    }
    
    int minimumSubarrayLength(vector<int>& a, int k) {
        vector<int> v(31,0);
        int n = a.size(), res = INT_MAX;
        int i=0;
        for(int j=0;j<n;j++){
            update(v,a[j],1);
            while(i<=j && getOr(v)>=k){
                res = min(res,(j-i+1));
                update(v,a[i],-1);
                i++;
            }
        }
        
        return res==INT_MAX ? -1: res;
    }
};