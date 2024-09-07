class Solution {
public:
    
    struct Node
    {
        int isEnd;
        Node* child[26];
        Node(){
            isEnd = 0;
            for(int i=0;i<26;i++) child[i]=NULL;
        }
    };
    int f;
    set<string> v;
    Node* T;

    void Insert(string s){
        Node* root = T;
        for(char ch: s){
            if(!root->child[ch-'a']){
                root->child[ch-'a'] = new Node();
            }
            root = root->child[ch-'a'];
        }
        root->isEnd = 1;
    }

    int isPrefix(string s){
        Node* root = T;
        for(char ch: s){
            if(!root->child[ch-'a']) return 0;
            root = root->child[ch-'a'];
        }
        if(root->isEnd) return 2;
        return 1;
    }

    void dfs(vector<vector<char>>& a,string s,int i,int j,int n,int m){
        // if(f) return;
        if(i<0 || j<0 || i==n || j==m || a[i][j]=='-') return;
        
        // cout<<s<<"\n";
        char ch = a[i][j];
        
        s+=ch;
        int flag = isPrefix(s);
        if(!flag) return;
        if(flag==2){
            v.insert(s);
            // f = 1;
            // return;
        }
        
        a[i][j] = '-';
        dfs(a,s,i-1,j,n,m);
        dfs(a,s,i+1,j,n,m);
        dfs(a,s,i,j-1,n,m);
        dfs(a,s,i,j+1,n,m);
        a[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& a, vector<string>& w) {
        T = new Node();
        for(string s: w){
            Insert(s);
        }
        
        vector<string> ans;
        v.clear();
        int n = a.size();
        int m = a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                f = 0;
                // if(a[i][j]=='e'){
                //     cout<<a[i][j]<<"x\n";
                //     cout<<i<<" "<<j<<"\n";
                // }
                dfs(a,"",i,j,n,m);
            }
        }
        for(auto it: v) ans.push_back(it);
        return ans;
    }
};