class Solution {
public:
    int rec(vector<int>& a,int l,int r){
        if(l>r) return INT_MIN;
        int mid = (l+r)/2;
        int lval=0,rval = 0;
        for(int i=mid-1,cursum=0;i>=l;i--){
            cursum+=a[i];
            lval = max(lval,cursum);
        }
        for(int i=mid+1,cursum=0;i<=r;i++){
            cursum+=a[i];
            rval = max(rval,cursum);
        }
        return max({rec(a,l,mid-1),rec(a,mid+1,r),lval+a[mid]+rval});
    }
    int maxSubArray(vector<int>& a) {
        return rec(a,0,a.size()-1);
    }
};