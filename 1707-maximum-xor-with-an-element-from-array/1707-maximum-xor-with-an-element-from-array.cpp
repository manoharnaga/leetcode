
class Solution {
public:
    struct TrieNode{
        int isEnd;
        TrieNode* child[2];
        TrieNode(){
            isEnd = 0;
            child[0]=child[1]=NULL;
        }
    };

    void Insert(TrieNode* T,int x){
        TrieNode* root = T;
        for(int i=30;i>=0;i--){
            int bit = (1<<i) & x ? 1: 0;
            if(!root->child[bit]){
                root->child[bit] =  new TrieNode();
            }
            root = root->child[bit];
        }
        root->isEnd = 1;
    }

    int maxXor(TrieNode* T,int x){
        TrieNode* root = T;
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
        
        vector<vector<int>> offQ;
        
        for(int j=0;j<m;j++){
            offQ.push_back({queries[j][1],queries[j][0],j});
        }
        
        sort(a.begin(),a.end());
        sort(offQ.begin(),offQ.end());
        
        // for(auto it: offQ) cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
        
        int i=0;
        vector<int> ans(m);
        TrieNode* root = new TrieNode();

        for(auto it: offQ){
            while(i<n && a[i]<=it[0]){
                Insert(root,a[i]);
                i++;
            }

            if(i!=0){
                ans[it[2]] = maxXor(root,it[1]);
            }
            else{
                ans[it[2]] = -1;
            }
        }
        return ans;
    }
};