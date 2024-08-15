class Solution {
public:
    struct TrieNode{
        int isEnd;
        TrieNode* child[2];
        TrieNode(){
            isEnd = 0;
            child[0] = child[1] = NULL;
        }
    };

    void Insert(TrieNode* T,int x){
        TrieNode* root = T;
        for(int i=30;i>=0;i--){
            int bit = ((1<<i) & x) ? 1:0;
            // cout<<bit<<"\n";
            if(!root->child[bit]){
                root->child[bit] = new TrieNode();
            }
            root = root->child[bit];
        }
        root->isEnd = 1;
    }

    int maxXor(TrieNode* T,int x){
        TrieNode* root = T;
        TrieNode* r1,r2;
        int ans = 0;
        for(int i=30;i>=0;i--){
            int bit = ((1<<i) & x) ? 1:0;
            if(root->child[1-bit]){
                ans += (1<<i);
                root = root->child[1-bit];
            }
            else{
                root = root->child[bit];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for(int val: nums){
            Insert(root,val);
        }
        int ans = 0;
        for(int val: nums){
            int maxval = maxXor(root,val);
            ans = max(ans,maxval);
        }
        return ans;
    }
};