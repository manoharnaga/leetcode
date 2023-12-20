class Solution {
public:
    
    vector<int> searchRange(vector<int>& a, int x) {
        int n = a.size();
        int low1 = 0, high1 = n-1,low2 = 0,high2 = n-1;
        int x1=-1,x2=-1;
        while(low1<=high1 || low2<=high2){
            int mid1 = (high1-low1)/2 + low1;
            int mid2 = (high2-low2)/2 + low2;
            if(low1<=high1){
                if(a[mid1]==x){
                    x1 = mid1;
                    high1 = mid1-1;
                }
                else if(a[mid1]>x){
                    high1 = mid1-1;
                }
                else{
                    low1 = mid1+1;
                }
            }
            if(low2<=high2){
                if(a[mid2]==x){
                    x2 = mid2;
                    low2 = mid2+1;
                }
                else if(a[mid2]>x){
                    high2 = mid2-1;
                }
                else{
                    low2 = mid2+1;
                }
            }
        }
        return {x1,x2};
    }
};