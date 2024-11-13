class Solution {
public:
    int minSubArrayLen(int k, vector<int>& a) {
        int n = a.size();
        int i=0,j=0,sum=0,res=INT_MAX;
        while(j<n){
            if(sum<k){
                sum+=a[j++];
            }
            else{
                sum-=a[i++];
            }
            if(sum>=k) res = min(res,(j-i));
        }
        while(i<n && (sum-a[i])>=k) sum-=a[i++];
        if(sum>=k) res=min(res,(j-i));
        
        return (res==INT_MAX?0:res);
    }
};