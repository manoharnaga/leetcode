class Trie {
    struct Node{
        Node* v[26];
        bool end;
        Node(){
            for(int i=0;i<26;i++) v[i]=nullptr;
            end = false;
        }
    };
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* trav = root;
        for(char ch: word){
            if(!trav->v[ch-'a']){
                trav->v[ch-'a'] = new Node();
            }
            trav = trav->v[ch-'a'];
        }
        trav->end = true;
    }
    
    bool search(string word) {
        Node* trav = root;
        for(char ch: word){
            if(!trav->v[ch-'a']) return false;
            trav = trav->v[ch-'a'];
        }
        return trav->end;
    }
    
    bool startsWith(string prefix) {
        Node* trav = root;
        for(char ch: prefix){
            if(!trav->v[ch-'a']) return false;
            trav = trav->v[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */