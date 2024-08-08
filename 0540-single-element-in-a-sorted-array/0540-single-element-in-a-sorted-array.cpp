class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int low = 0,high = a.size()-1;
        int n = a.size();
        while(low<=high){
            int mid = (low+high)/2;
            int cnt = mid+1;
            int cnt2 = n-1-mid;
            cout<<low<<" "<<mid<<" "<<high<<"\n";
            if((mid-1)>=0 && a[mid-1]==a[mid]){
                cout<<cnt<<endl; 
                if(cnt%2) high = mid-1;
                else      low = mid+1;
            }
            else if((mid+1)<n && a[mid]==a[mid+1]){
                if(cnt2%2) high = mid-1;
                else       low = mid+1;
            }
            else{
                return a[mid];
            }
        }
        return a[low];
    }
};