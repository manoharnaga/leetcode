class Solution {
public:
    int check(vector<int>& a,int n,int x){
        int cnt = 0;
        for(int val: a){
            int k = (val/x)+((val%x)>0);
            cnt += k;
        }
        return (cnt<=n);
    }
    
    int minimizedMaximum(int n, vector<int>& a) {
        int mx = *max_element(a.begin(),a.end());
        int low = 1,high = mx;
        int res = mx;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(a,n,mid)){
                res = min(res,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};