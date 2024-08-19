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
    TreeNode* found;
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        
        TreeNode* l = rec(root->left,p,q);
        TreeNode* r = rec(root->right,p,q);
        
        if(found){
            return found;
        }
        
        if(root==p || root==q){
            if(l==p || l==q || r==p || r==q){
                found = root; // p or q is ancestor
                return found;
            }
            else{
                return root;
            }
        }
        
        if((l==p && r==q) || (l==q && r==p)){
            found = root; // p,q have diff ancestor
            return found;
        }
        
        if(l==p || l==q) return l;
        if(r==p || r==q) return r;
        
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        found = NULL;
        rec(root,p,q);
        return found;
    }
};