class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int n = a.size();
        int j = 0;
        for(int i=0;i<n;i++){
            if(a[j]!=val){
                j++;
            }
            else{
                if(i>j && a[i]!=val){
                    swap(a[i],a[j]);
                    j++;
                }
            }
        }
        return j;
    }
};