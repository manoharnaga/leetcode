class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int k = 0, i = 0;
        int n = a.size();
        while(i<n){
            // cout<<k<<" "<<i<<"\n";
            int x = k++;
            int y = i;
            int p,q;
            p = q = 0;
            if((i+1)<n && a[i]==a[i+1]){
                p = k++;
                q = i+1;
                // swap(a[k++],a[i+1]);
                if((i+2)<n && a[i]==a[i+2]){
                    i = i+2;
                    while(i<n && a[i-1]==a[i]) i++;
                    i-=2;
                }
                i++;
            }
            // cout<<x<<" "<<y<<"x\n";
            // cout<<p<<" "<<q<<"p\n";
            swap(a[x],a[y]);
            swap(a[p],a[q]);
            i++;
        }
        return k;
    }
};