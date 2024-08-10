class Solution {
public:
    void next_permutation(string& s){
        int n = s.size();
        int ind = -1;
        for(int i=n-1;i>0;i--){
            if(s[i-1]<s[i]){
                ind = i;
                break;
            }
        }
        if(ind==-1){
            reverse(s.begin(),s.end());
            return;
        }
        
        reverse(s.begin()+ind,s.end());
        
        for(int j=ind;j<n;j++){
            if(s[ind-1]<s[j]){
                swap(s[ind-1],s[j]);
                break;
            }
        }
    }
    string getPermutation(int n, int k) {
        string s = "";
        int sz = 1;
        for(int i=1;i<=n;i++){
            s += to_string(i);
            sz *= i;
        }
        for(int i=0;i<k-1;i++){
            next_permutation(s);
        } 
        return s;
    }
};