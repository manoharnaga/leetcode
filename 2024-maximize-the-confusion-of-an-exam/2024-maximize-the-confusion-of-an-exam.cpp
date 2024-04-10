class Solution {
public:
    int func(string a,int k,char ch){
        int n = a.size();
        int s=0,e=0;
        int ans = 0;
        while(e<n){
            if(a[e]!=ch){
                while(s<=e && k<=0){
                    if(a[s]!=ch){
                        k++;
                    }
                    s++;
                }
                k--;
            }
            ans = max(ans,(e-s+1));
            e++;
        }
        return ans;
    }
    int maxConsecutiveAnswers(string x, int k) {
        int l = func(x,k,'F');
        int r = func(x,k,'T');
        return max(l,r);
    }
};