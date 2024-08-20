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
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if(root->left){
            TreeNode* l = root->left;
            int lval = l->val;
            while(l){
                lval = max(lval,l->val);
                l = l->right;
            }
            if(lval>=root->val) return false;
        }
        
        if(root->right){
            TreeNode* r = root->right;
            int rval = r->val;
            while(r){
                rval = min(rval,r->val);
                r = r->left;
            }
            if(root->val>=rval) return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }
};