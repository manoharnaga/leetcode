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
    
    pair<TreeNode*,TreeNode*> rec(TreeNode* root){
        if(!root) return {NULL,NULL};
        
        pair<TreeNode*,TreeNode*> l,r;
        l = rec(root->left);
        r = rec(root->right);
        
        // if(root->val==2){
        //     cout<<l.first->val<<" "<<r.first->val<<"\n";
        //     cout<<l.second->val<<" "<<r.second->val<<"\n";
        // }
        
        root->left = NULL;
        if(!l.first && !r.first){
            return {root,root};
        }
        else if(!l.first){
            root->right = r.first;
            return {root,r.second};
        }
        else if(!r.first){
            root->right = l.first;
            return {root,l.second};
        }
        else{
            root->right = l.first;
            l.second->right = r.first;
            return {root,r.second};
        }
    }
    
    void flatten(TreeNode* root) {
        pair<TreeNode*,TreeNode*> res = rec(root);
        root = res.first;
    }
};