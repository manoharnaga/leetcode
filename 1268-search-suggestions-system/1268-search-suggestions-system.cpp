class Solution {
public:
    struct Node{
        Node* v[26];
        int end;
        vector<int> x;
        Node(){
            end = 0;
            x.resize(0);
            for(int i=0;i<26;i++) v[i]=nullptr;
        }
    };
    Node* root;
    void Insert(Node* root,string s,int ind){
        Node* trav = root;
        for(char ch: s){
            if(!trav->v[ch-'a']){
                trav->v[ch-'a'] = new Node();
            }
            trav = trav->v[ch-'a'];
            if(trav->x.size()<3){
                trav->x.push_back(ind);
            }
        }
        trav->end = 1;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Node();
        int n = products.size();
        sort(products.begin(),products.end());
        for(int i=0;i<n;i++){
            Insert(root,products[i],i);
        }
        
        vector<vector<string>> ans;
        Node* trav = root;
        for(int i=0;i<searchWord.size();i++){
            char ch = searchWord[i];
            if(!trav->v[ch-'a']){
                while(i<searchWord.size()){
                    ans.push_back({});
                    i++;
                }
                break;
            }
            trav = trav->v[ch-'a'];
            vector<string> temp;
            for(int ind: trav->x){
                temp.push_back(products[ind]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};