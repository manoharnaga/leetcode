class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int ind = -1;
        for(int i=n-1;i>0;i--){
            if(a[i-1]<a[i]){
                ind = i-1;
                break;
            }
        }  
        if(ind==-1){
            reverse(a.begin(),a.end());
            return;
        }
        // cout<<ind+1<<" "<<(ind+1+(n-1-ind)/2)<<"\n";
        int j=n-1;
        for(int i=ind+1;i<(ind+1+(n-1-ind)/2);i++){
            swap(a[i],a[j--]);
        }
        for(int i=ind+1;i<n;i++){
            if(a[i]>a[ind]){
                swap(a[i],a[ind]);
                break;
            }
        }
    }
};