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
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));
        reverse(nums.begin()+(nums.size()-k),nums.end());
        reverse(nums.begin(),nums.end());
    }
};