class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i=m-1;
        int j=0;
        while(i>=0 && j<n && a[i]>b[j]){
            swap(a[i],b[j]);
            i--;j++;
        }
        sort(a.begin(),a.begin()+m);
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++) a[i+m]=b[i];
    }
};