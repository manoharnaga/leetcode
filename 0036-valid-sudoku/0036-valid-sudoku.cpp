class Solution {
public:
    int ans;
    bool rec(vector<vector<char>>& a,vector<int>& r,vector<int>& c,vector<int>& b){
        int f = 1;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(ans) return 1;
                if(a[i][j]=='.'){
                   f=0;
                   for(char ch='1';ch<='9';ch++){
                       int val = ch-'0';
                       int ind = (i/3+j/3);
                       cout<<ind<<"\n";
                       if((r[i] & (1<<val)) || (c[j] & (1<<val)) || (b[ind] & (1<<val))){
                          continue; 
                       }
                       a[i][j] = ch;
                       cout<<ch<<"\n";
                       r[i] = r[i] | (1<<val);
                       c[j] = c[j] | (1<<val);
                       b[ind] = b[ind] | (1<<val);
                       if(rec(a,r,c,b)) return 1;
                       r[i] = r[i] ^ (1<<val);
                       c[j] = c[j] ^ (1<<val);
                       b[ind] = b[ind] ^ (1<<val);
                   }
                }
                // if(a[i][j]=='.') return 0; 
            }
        }
        if(f){
            ans = 1;
        }
        return f;
    }
    bool isValidSudoku(vector<vector<char>>& a) {
        ans = 0;
        vector<int> r(9,0),c(9,0),b(9,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(a[i][j]!='.'){
                    int val = a[i][j]-'0';
                    int ind = ((i/3)*3+j/3);
                    if((r[i] & (1<<val)) || (c[j] & (1<<val)) || (b[ind] & (1<<val))){
                       return false;
                    }
                    r[i] = r[i] | (1<<val);
                    c[j] = c[j] | (1<<val);
                    b[ind] = b[ind] | (1<<val);
                }
            }
        }
        return true;
    }
};