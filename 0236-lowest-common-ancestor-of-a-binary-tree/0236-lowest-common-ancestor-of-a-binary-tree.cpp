/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {    
    TreeNode* ans;
    vector<int> rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return {0,0};
        vector<int> x = rec(root->left,p,q);
        if(ans) return x;
        vector<int> y = rec(root->right,p,q);
        x[0] = (root->val==p->val) || x[0] || y[0];
        x[1] = (root->val==q->val) || x[1] || y[1];
        if(!ans && x[0] && x[1]){
            ans = root;
        }
        return x;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;
        rec(root,p,q);
        return ans;
    }
};