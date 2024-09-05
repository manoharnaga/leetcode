class Solution {
public:
    int findMin(vector<int>& a) {
        int low = 0;
        int high = a.size()-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if((high-low+1)<=3){
                return min({ans,a[low],a[mid],a[high]});
            }
            ans = min(ans,a[mid]);
            if(a[low]<=a[mid] && a[mid]<=a[high]) return min(ans,a[low]);
            else if(a[low]<a[mid] && a[mid]>a[high]) low = mid+1;
            else if(a[low]>a[mid] && a[mid]<a[high]){
                high = mid-1;
            }
            else{
                cout<<low<<" "<<mid<<" "<<high<<"bro\n";
            }
        }
        return ans;
    }
};