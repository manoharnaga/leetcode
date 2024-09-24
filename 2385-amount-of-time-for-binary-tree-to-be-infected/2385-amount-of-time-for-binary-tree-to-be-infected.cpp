/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    #define N 100010
    vector<int> adj[N];
    void io(TreeNode* root){
        if(!root) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        io(root->left);
        io(root->right);
    }

    int amountOfTime(TreeNode* root, int start) {
        io(root);
        vector<int> vist(N);
        queue<int> q;
        q.push(start);
        vist[start] = 1;
        int mins = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int at = q.front();
                q.pop();
                for(int it: adj[at]){
                    if(!vist[it]){
                        q.push(it);
                        vist[it] = 1;
                    }
                }
            }
            mins++;
        }
        return (mins-1);
    }
};