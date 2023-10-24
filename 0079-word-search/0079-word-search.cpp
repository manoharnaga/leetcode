class Solution {
public:
    int rec(vector<vector<char>>& board,string s,int n,int m,int i,int j,int k){
        if(k==s.size()) return 1;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=s[k]) return 0;
        char ch=board[i][j];
        board[i][j]=' ';
        int f=rec(board,s,n,m,i+1,j,k+1) || rec(board,s,n,m,i-1,j,k+1) || rec(board,s,n,m,i,j-1,k+1) || rec(board,s,n,m,i,j+1,k+1);
        board[i][j]=ch;
        return f;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        if(word.empty()) return true;
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(rec(board,word,n,m,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};