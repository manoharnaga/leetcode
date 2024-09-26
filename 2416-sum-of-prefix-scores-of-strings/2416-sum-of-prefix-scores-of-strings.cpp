class Solution {
public:
    struct Node{
        int cnt;
        int isEnd;
        Node* child[26];
        Node(){
            cnt = 0;
            isEnd = 0;
            for(int i=0;i<26;i++) child[i] = nullptr;
        }
    };

    void Insert(Node* root,string& s){
        for(char ch: s){
            int k = ch-'a';
            if(!root->child[k]){
                root->child[k] = new Node();
            }
            root = root->child[k];
            root->cnt++;
        }
        root->isEnd = 1;
    }

    int search(Node* root,string& s){
        for(char ch: s){
            int k = ch-'a';
            if(!root->child[k]) break;
            root = root->child[k];
        }
        return root->cnt;
    }
    
    void agg(Node* root,int prev){
        root->cnt += prev;
        for(char ch='a';ch<='z';ch++){
            int k = ch-'a';
            if(root->child[k]){
                agg(root->child[k],root->cnt);
            }
        }
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        Node* root = new Node();
        for(string& s: words) Insert(root,s);
        
        int n = words.size();
        vector<int> ans(n);
        
        agg(root,0);
        for(int i=0;i<n;i++){ // 1000
            ans[i] = search(root,words[i]);
        }
        return ans;
    }
};