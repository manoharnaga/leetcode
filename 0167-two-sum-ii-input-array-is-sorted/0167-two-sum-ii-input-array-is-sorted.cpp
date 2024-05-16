class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        int low = 0,high = a.size()-1;
        while(low<high){
            int val = a[low]+a[high];
            if(val>x){
                high--;
            }
            else if(val<x){
                low++;
            }
            else{
                return {low+1,high+1};
            }
        }
        return {-1,-1};
    }
};