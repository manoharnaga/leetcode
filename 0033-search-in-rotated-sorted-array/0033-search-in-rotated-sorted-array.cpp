class Solution {
public:
    int search(vector<int>& a, int x) {
        int low = 0,high = a.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            // cout<<low<<" "<<high<<" "<<mid<<"\n";
            if(a[mid]==x){
                return mid;
            }
            else if(a[mid]<x && x<=a[high]){
                low = mid+1;
            }
            else if(a[low]<=x && x<a[mid]){
                high = mid-1;
            }
            else if(a[mid]<=a[high]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};