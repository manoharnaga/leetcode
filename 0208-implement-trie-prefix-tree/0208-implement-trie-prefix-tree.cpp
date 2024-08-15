
class Trie {
public:
    struct TrieNode{
        bool isEnd;
        TrieNode* child[26];
        TrieNode(){
            isEnd = false;
            for(int i=0;i<26;i++) child[i]=NULL;
        }
    };

    TrieNode* T;
    Trie() {
        T = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* root = T;
        for(char ch: word){
            if(!root->child[ch-'a']){
                root->child[ch-'a'] = new TrieNode();
            }
            root = root->child[ch-'a'];
        }
        root->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* root = T;
        for(char ch: word){
            if(!root->child[ch-'a']) return false;
            root = root->child[ch-'a'];
        }
        return root->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* root = T;
        for(char ch: prefix){
            if(!root->child[ch-'a']) return false;
            root = root->child[ch-'a'];
        }
        return true;
    }
};