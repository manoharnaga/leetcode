class Solution {
public:
    
    vector<int> searchRange(vector<int>& a, int x) {
        int n = a.size();
        int low = 0, high = n-1;
        int x1=-1,x2=-1;
        while(low<=high){
            int mid = (high-low)/2 + low;
            if(a[mid]==x){
                x1 = mid;
                high = mid-1;
            }
            else if(a[mid]>x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        low = 0, high = n-1;
        while(low<=high){
            int mid = (high-low)/2 + low;
            if(a[mid]==x){
                x2 = mid;
                low = mid+1;
            }
            else if(a[mid]>x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {x1,x2};
    }
};