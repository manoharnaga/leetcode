class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int n = a.size();
        if(n==1) return 0;
        int low = 0, high = n-1;
        
        while(low<=high){
            int mid = (high-low)/2 + low;
            int targ = mid;
            if((mid-1)>=0 && a[mid]<a[mid-1]){
                targ = mid-1;
            }
            if((mid+1)<n && a[targ]<a[mid+1]){
                targ = mid+1;
            }
            if(targ==mid) return mid;
            if(targ<mid){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};