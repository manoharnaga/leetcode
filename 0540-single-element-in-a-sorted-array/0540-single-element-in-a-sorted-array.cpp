class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int low = 0,high = a.size()-1;
        int n = a.size();
        while(low<high){
            int mid = (low+high)/2;
            // cout<<low<<" "<<mid<<" "<<high<<"\n";
            if((high-low+1)==3){
                if(a[low]==a[low+1]) return a[high];
                else                 return a[low];
            }
            int cnt1=0,cnt2=0;
            if((mid-1)>=0 && a[mid-1]==a[mid]){
                cnt1 = mid-1-low;
                if(cnt1%2) high = mid-2;
                else       low = mid+1;
            }
            else if((mid+1)<n && a[mid+1]==a[mid]){
                cnt2 = high-mid-1;
                if(cnt2%2) low = mid+2;
                else       high = mid-1;
            }
            else{
                return a[mid];
            }
        }
        return a[low];
    }
};