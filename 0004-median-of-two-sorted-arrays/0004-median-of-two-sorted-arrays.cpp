class Solution {
public:

    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        if(n>m) return findMedianSortedArrays(b,a);
        int left = (n+m+1)/2;
        int low = 0,high = n;
        while(low<=high){
            int midl = (low+high)/2;    //  x => no. of elems in left half from arr1
            int midr = left-midl;       // n/2-x => no. of elems in left half from arr2
            
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            
            if(midl<n) r1=a[midl];
            if(midr<m) r2=b[midr];
            
            if((midl-1)>=0) l1=a[midl-1];
            if((midr-1)>=0) l2=b[midr-1];
            
            // cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<"\n";
            if(l1<=r2 && l2<=r1){
                int sz = n+m;
                if(sz%2==1) return max(l1,l2);
                else       return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }
            else if(l1>r2){ // more elems from arr1 in left half
                high = midl-1;
            }
            else low = midl+1;
        }
        return 0.0;
    }
};