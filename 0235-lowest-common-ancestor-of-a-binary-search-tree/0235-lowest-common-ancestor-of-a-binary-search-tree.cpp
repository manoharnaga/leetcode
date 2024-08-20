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
public:
    vector<TreeNode*> rec(TreeNode* root,TreeNode* p){
        vector<TreeNode*> v;
        while(root){
            v.push_back(root);
            if(p->val==root->val){
                break;
            }
            else if(p->val<root->val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return v;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pv = rec(root,p);
        vector<TreeNode*> qv = rec(root,q);
        for(int i=min(pv.size(),qv.size())-1;i>=0;i--){
            if(pv[i]==qv[i]) return pv[i];
        }
        return nullptr;
    }
};