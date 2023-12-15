class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int i=0,j=1;
        int n = a.size();
        while(j<n){
            if(a[i]==0 && a[j]!=0){
                swap(a[i],a[j]);
                i++;
                j++;
            }
            else if(a[i]==0 && a[j]==0){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
    }
};