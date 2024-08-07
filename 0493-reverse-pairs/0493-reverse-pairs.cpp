class Solution {
public:
    typedef long long ll;
    ll ans;
    int bin(vector<ll>& a,int x){
        int low = 0,high = a.size()-1;
        int ind = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(a[mid]>=x){
                high = mid-1;
            }
            else{
                ind = mid;
                low = mid+1;
            }
        }
        return ind;
    }
    void merge(vector<int>& a,int low,int mid,int high){
        vector<int> L(mid-low+1),R(high-mid);
        for(int i=low;i<=mid;i++) L[i-low]=a[i];
        for(int i=mid+1;i<=high;i++) R[i-mid-1]=a[i];
        int n = L.size(),m = R.size();
        int i=0,j=0,k=low;
        vector<ll> v(m);
        for(int i=0;i<m;i++) v[i]=(2ll*R[i]);
        for(int j=0;j<n;j++){
            int ind = bin(v,L[j]);
            if(ind!=-1) ans += (ind+1);
        }
        while(i<n && j<m){
            if(L[i]<=R[j]){
                a[k] = L[i++];
            }
            else{
                a[k] = R[j++];
            }
            k++;
        }
        while(i<n){
            a[k++]=L[i++];
        }
        while(j<m){
            a[k++]=R[j++];
        }
    }
    void mergeSort(vector<int>& a,int low,int high){
        if(low>=high) return;
        int mid = (low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
    int reversePairs(vector<int>& a) {
        ans = 0ll;
        int n = a.size();
        mergeSort(a,0,n-1);
        // for(int val: a) cout<<val<<" ";
        // cout<<"\n";
        return ans;
    }
};