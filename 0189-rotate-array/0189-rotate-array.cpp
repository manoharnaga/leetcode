class Solution {
public:
    void rev(vector<int>& a,int i,int j){
        int p = 0;
        for(int k=i;p<(j-i+1)/2;k++){
            swap(a[k],a[j-p]);
            p++;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        rev(nums,0,n-k-1);
        rev(nums,n-k,n-1);
        rev(nums,0,n-1);
    }
};