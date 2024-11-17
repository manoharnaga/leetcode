class Solution {
public:
    bool search(vector<int>& a, int x) {
        int n = a.size();
        int low = 0,high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(a[mid]==x) return true;
            
            // case __--__
            if(a[low]==a[mid] && a[mid]==a[high]){
                low++;high--;
                continue;
            }
            if(a[low]<=a[mid]){
                if(a[low]<=x && x<=a[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(a[mid]<=x && x<=a[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};