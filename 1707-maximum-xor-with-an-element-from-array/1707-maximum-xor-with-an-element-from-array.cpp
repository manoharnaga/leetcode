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

    void Insert(TrieNode* root,int x){
        for(int i=30;i>=0;i--){
            int bit = (x>>i) & 1;
            if(!root->child[bit]){
                root->child[bit] = new TrieNode();
            }
            root = root->child[bit];
        }
        root->isEnd = 1;
    }

    int maxXor(TrieNode* root,int x){
        int ans = 0;
        for(int i=30;i>=0;i--){
            int bit = (x>>i) & 1;
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

    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        int m = queries.size();
        vector<int> ans(m);
        sort(a.begin(),a.end());
        vector<vector<int>> q;
        for(int i=0;i<m;i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
        sort(q.begin(),q.end());
        
        int j=0;
        TrieNode* root = new TrieNode();

        for(int i=0;i<m;i++){
            auto it = q[i];
            while(j<n && a[j]<=it[0]){
                Insert(root,a[j]);
                j++;
            }

            if(j!=0){
                ans[it[2]] = maxXor(root,it[1]);
            }
            else{
                ans[it[2]] = -1;
            }
        }
        return ans;
    }
};