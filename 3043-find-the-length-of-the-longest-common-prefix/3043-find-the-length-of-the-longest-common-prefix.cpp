class Solution {
public:
    struct Node{
        int isEnd;
        Node* child[10];
        Node(){
            isEnd = 0;
            for(int i=0;i<10;i++) child[i] = nullptr;
        }
    };

    void Insert(Node* T,string s){
        Node* root = T;
        for(char ch: s){
            int k = ch-'0';
            if(!root->child[k]) root->child[k] = new Node();
            root = root->child[k];
        }
        root->isEnd = 1;
    }
    int search(Node* root,string s){
        int cnt = 0;
        for(char ch: s){
            int k = ch-'0';
            if(!root->child[k]) return cnt;
            cnt++;
            root = root->child[k];
        }
        return cnt;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node* root = new Node();
        for(int x: arr1){
            string num = to_string(x);
            Insert(root,num);
        }
        int ans = 0;
        for(int x: arr2){
            ans = max(ans,search(root,to_string(x)));
        }
        return ans;
    }
};