class Solution {
public:
    string convert(string s, int n) {
        if(n==1) return s;
        int m = s.size();
        vector<vector<char>> a(n,vector<char>(max(n,m),'-'));
        int k=0;
        int i=0,j=0;
        int f = 0;
        while(k<m){
            if(!f){
                // cout<<i<<" "<<j<<"\n";
                a[i][j] = s[k];
                i++;
            }
            else{
                a[i][j] = s[k];
                i--;j++;
            }
            k++;
            if(i==-1){
                i = 1;
                j--;
                f = 0;
            }
            if(i==n){
                i = n-2;
                j++;
                f = 1;
            }
        }
        s = "";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<a[i][j]<<" ";
                if(a[i][j]!='-') s+=a[i][j];
            }
            // cout<<"\n";
        }
        return s;
    }
};