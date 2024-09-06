class WordDictionary {
public:
    struct Node{
        int isEnd;
        Node* child[26];
        Node(){
            isEnd = 0;
            for(int i=0;i<26;i++) child[i]=NULL;
        }
    };

    Node* T;
    WordDictionary() {
        T = new Node();
    }
    
    void addWord(string word) {
        Node* root = T;
        for(char ch: word){
            ch = ch-'a';
            if(!root->child[ch]) root->child[ch] = new Node();
            root = root->child[ch];
        }
        root->isEnd = 1;
    }
    
    bool search2(Node* root,string& word,int idx){
        for(int i=idx;i<word.size();i++){
            char ch = word[i];
            if(ch=='.'){
                int f = 0;
                // cout<<word<<"\n";
                for(int k=0;k<26;k++){
                    if(root->child[k]){
                        // printf("%c\n",k);
                        if(search2(root->child[k],word,i+1)){
                            f=1;
                            break;
                        }
                    }
                }
                return f;
            }
            ch = ch-'a';
            if(!root->child[ch]) return false;
            root = root->child[ch];
        }
        return root->isEnd;
    }
    bool search(string word) {
        return search2(T,word,0);
    }
};