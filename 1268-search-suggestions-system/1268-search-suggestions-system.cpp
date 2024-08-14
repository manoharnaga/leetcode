class Solution {
public:
    struct TrieNode{
        int isEnd;
        TrieNode* child[26];
        TrieNode(){
            isEnd = 0;
            for(int i=0;i<26;i++) child[i]=NULL;
        }
    };

    void Insert(TrieNode* T,string s){
        TrieNode* root = T;
        for(char ch: s){
            if(!root->child[ch-'a']){
                root->child[ch-'a'] = new TrieNode();
            }
            root = root->child[ch-'a'];
        }
        root->isEnd = 1;
    }

    void rec(TrieNode* root,vector<string>& ans,string s){
        if(ans.size()==3) return;
        if(root->isEnd){
            ans.push_back(s);
        }
        for(char ch='a';ch<='z';ch++){
            if(root->child[ch-'a']){
                rec(root->child[ch-'a'],ans,(s+ch));
            }
        }
    }
    vector<string> search(TrieNode* T,string x){
        TrieNode* root = T;
        for(char ch: x){
            if(!root->child[ch-'a']) return {};
            root = root->child[ch-'a'];
            // cout<<ch<<" ";
        }
        // cout<<"\n";
        vector<string> ans;
        rec(root,ans,x);
        return ans;
    }

    vector<vector<string>> suggestedProducts(vector<string>& a, string target) {
        vector<vector<string>> ans;
        int n = a.size();
        TrieNode* root = new TrieNode();
        for(string s: a){
            Insert(root,s);
        }
        string s="";
        for(char ch: target){
            s+=ch;
            vector<string> v = search(root,s);
            ans.push_back(v);
        }
        return ans;
    }
};