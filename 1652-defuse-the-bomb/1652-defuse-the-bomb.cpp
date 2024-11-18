class Solution {
public:
    vector<int> decrypt(vector<int>& a, int k) {
        int n = a.size();
        vector<int> ans(n);
        if(k==0){
            return ans;
        }
        else if(k>0){
            for(int i=0;i<n;i++){
                int sum = 0;
                for(int j=(i+1)%n,cnt = 0;cnt<k;j=(j+1)%n,cnt++){
                    sum+=a[j];
                }
                ans[i] = sum;
            }
        }
        else{
            k = abs(k);
            for(int i=0;i<n;i++){
                int sum = 0;
                for(int j=(i-1+n)%n,cnt = 0;cnt<k;j=(j-1+n)%n,cnt++){
                    sum+=a[j];
                }
                ans[i] = sum;
            }
        }
        return ans;
    }
};